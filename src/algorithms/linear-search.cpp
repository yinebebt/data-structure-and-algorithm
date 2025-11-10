#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> array = {10, 4, 8, 2, 6, 1, 7, 3, 9, 5};
    int target = 6;

    int index = linearSearch(array, target);

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
