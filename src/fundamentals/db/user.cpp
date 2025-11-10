#include <iostream>
#include <postgresql/libpq-fe.h>

struct UserData
{
    std::string username;
    std::string email;
    std::string password;
};

bool createTableIfNotExists(PGconn *connection)
{
    const char *createTableQuery =
        "CREATE TABLE IF NOT EXISTS test_user ("
        "id SERIAL PRIMARY KEY,"
        "username VARCHAR(100) NOT NULL,"
        "email VARCHAR(100) NOT NULL,"
        "password VARCHAR(100) NOT NULL,"
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
        ")";

    PGresult *result = PQexec(connection, createTableQuery);

    if (PQresultStatus(result) == PGRES_COMMAND_OK)
    {
        PQclear(result);
        std::cout << "Table 'test_user' ready." << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Error creating table: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);
        return false;
    }
}

bool insertUserData(PGconn *connection, const UserData &user)
{
    const char *insertQuery = "INSERT INTO test_user (username, email, password) VALUES ($1, $2, $3)";
    const char *paramValues[3] = {user.username.c_str(), user.email.c_str(), user.password.c_str()};

    PGresult *result = PQexecParams(connection, insertQuery, 3, nullptr, paramValues, nullptr, nullptr, 0);

    if (PQresultStatus(result) == PGRES_COMMAND_OK)
    {
        PQclear(result);
        return true;
    }
    else
    {
        std::cerr << "Error inserting user data: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);
        return false;
    }
}

int main()
{
    // Connection to PostgreSQL database
    PGconn *connection = PQconnectdb("dbname=postgres user=postgres password=postgres host=localhost");

    if (PQstatus(connection) != CONNECTION_OK)
    {
        std::cerr << "Connection failed: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return 1;
    }

    std::cout << "Connected to the database." << std::endl;

    // Create table if it doesn't exist
    if (!createTableIfNotExists(connection))
    {
        PQfinish(connection);
        return 1;
    }

    UserData user;
    std::cout << "Enter username: ";
    std::cin >> user.username;
    std::cout << "Enter email: ";
    std::cin >> user.email;
    std::cout << "Enter password: ";
    std::cin >> user.password;

    if (insertUserData(connection, user))
    {
        std::cout << "User data inserted successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to insert user data." << std::endl;
        PQfinish(connection);
        return 1;
    }

    PQfinish(connection);
    std::cout << "Connection closed." << std::endl;

    return 0;
}