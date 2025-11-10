#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    int index = binarySearch(sortedArray, target);
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
