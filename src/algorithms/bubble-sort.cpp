#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {6, 17, 42, 11, 9};

    std::cout << "Original array: ";
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}