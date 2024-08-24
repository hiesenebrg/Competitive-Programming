#include <iostream>
#include <vector>

// Function to merge two halves
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into the original array
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Recursive Merge Sort function with a base case
void mergeSort(std::vector<int>& arr, int left, int right) {
    // Base case: If the array has one or zero elements, it's already sorted
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main() {
    // Initialize the array
    std::vector<int> arr = std::vector<int>{38, 27, 43, 3, 9, 82, 10};
    int arrSize = arr.size();

    std::cout << "Given array is: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    // Perform merge sort
    mergeSort(arr, 0, arrSize - 1);

    std::cout << "Sorted array is: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
