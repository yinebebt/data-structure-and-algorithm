#include <iostream>

int main()
{
    int x = 42;

    int *ptr;
    ptr = &x;

    std::cout << "Value of x: " << *ptr << std::endl;

    *ptr = 100;
    std::cout << "Updated value of x: " << x << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Element " << i << ": " << *arrPtr << std::endl;
        arrPtr++;
    }
    arrPtr = arr;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Element " << i << ": " << arrPtr[i] << std::endl;
    }

    return 0;
}
