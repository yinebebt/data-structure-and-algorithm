#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> arr = {10, 34, 25, 22, 11};

    std::cout << "Original array: ";
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    selectionSort(arr);

    std::cout << "Sorted array: ";
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
