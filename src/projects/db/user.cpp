#include <iostream>
#include <postgresql/libpq-fe.h>

struct UserData
{
    std::string username;
    std::string email;
    std::string password;
};

bool insertUserData(PGconn *connection, const UserData &user)
{
    // Prepare SQL query
    const char *insertQuery = "INSERT INTO test_user (username, email, password) VALUES ($1, $2, $3)";
    const char *paramValues[3] = {user.username.c_str(), user.email.c_str(), user.password.c_str()};

    // Execute SQL query
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
    PGconn *connection = PQconnectdb("dbname=mydb user=myuser password=mypassword host=localhost"); // update these params.

    if (PQstatus(connection) == CONNECTION_OK)
    {
        std::cout << "Connected to the database." << std::endl;

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
        }

        PQfinish(connection);
        std::cout << "Connection closed." << std::endl;
    }
    else
    {
        std::cerr << "Connection failed: " << PQerrorMessage(connection) << std::endl;
    }

    return 0;
}