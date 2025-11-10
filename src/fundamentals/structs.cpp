#include <iostream>
#include <string>

// Define a struct
struct Person
{
    std::string name;
    int age;
    double height;

    void introduce()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Height: " << height << " feet" << std::endl;
    }
};

int main()
{
    // Create an instance of the struct
    Person person1;
    // Access and assign values to its members
    person1.name = "John Doe";
    person1.age = 30;
    person1.height = 6.0;

    // Initializing a struct at the time of declaration
    Person person2 = {"Robel", 18, 5.6};

    // Access and print the struct members
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    std::cout << "Height: " << person1.height << " feet" << std::endl;

    // Call the introduce() member function
    std::cout << "Member function Introduce :\n";
    person2.introduce();

    /*
     * Create an array of Person structs
     */
    Person people[3];

    // Initialize the elements
    people[0] = {"John", 30};
    people[1] = {"Alice", 25};
    people[2] = {"Bob", 35};

    // Access and print the data,
    // const: cannot be used to change the memory it points to.
    for (const Person &p : people)
    {
        std::cout << "Name: " << p.name << ", Age: " << p.age << std::endl;
    }

    return 0;
}
