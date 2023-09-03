#include <iostream>

int main()
{
    int x = 42;

    int *ptr; // Declare a pointer to an integer
    ptr = &x; // Assign the address of 'x' to the pointer 'ptr'

    // Access and print the value of 'x' through the pointer 'ptr'
    std::cout << "Value of x: " << *ptr << std::endl;

    *ptr = 100; // Change the value of 'x' through the pointer 'ptr'
    std::cout << "Updated value of x: " << x << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr; // points to the first element of the array

    // Access elements of the array using the pointer
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Element " << i << ": " << *arrPtr << std::endl;
        arrPtr++; // Move the pointer to the next element
    }
    arrPtr = arr; // Reset the pointer to the beginning of the array

    // Access elements of the array using pointer arithmetic
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Element " << i << ": " << arrPtr[i] << std::endl; // arrPtr[i] = *(arrPtr+i)
    }

    return 0;
}
