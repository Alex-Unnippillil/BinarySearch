#include <iostream>
#include <vector>

// Function for binary search
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target value is at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target value greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target value smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // Target value not found
    return -1;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Enter the elements of the array in sorted order:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the target value to search: ";
    std::cin >> target;

    // binary search function
    int index = binarySearch(arr, target);

    if (index != -1) {
        std::cout << "Target value was found at index " << index << std::endl;
    }
    else {
        std::cout << "Target value could not be found in the array" << std::endl;
    }

    // array elements displayed
    std::cout << "Array elements: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // occurrences counted
    int count = 0;
    for (int value : arr) {
        if (value == target) {
            count++;
        }
    }
    std::cout << "Occurrences of the target: " << count << std::endl;

    // sorted array check
    bool isSorted = true;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            isSorted = false;
            break;
        }
    }
    std::cout << "Array is" << (isSorted ? " " : " not ") << "sorted" << std::endl;

    // Find min max elments of array
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int element : arr) {
        if (element < minVal) {
            minVal = element;
        }
        if (element > maxVal) {
            maxVal = element;
        }
    }
    std::cout << "Minimum value: " << minVal << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;

    return 0;
}
