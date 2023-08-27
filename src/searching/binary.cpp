#include <iostream>
#include <vector>

int binarySearch(int arr[],int size, int target) {
    int left = 0;
    int right = size-1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (arr[mid] == target) {
            return mid; // Element found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main() {
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);

    int index = binarySearch(sortedArray,size, target);
    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
