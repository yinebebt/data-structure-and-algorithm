#include <iostream>

int linearSearch(const int arr[], int size, int target)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main()
{
    int array[] = {10, 4, 8, 2, 6, 1, 7, 3, 9, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 6;

    int index = linearSearch(array, size, target);

    if (index != -1)
    {
        std::cout << "Element found at index " << index << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}
