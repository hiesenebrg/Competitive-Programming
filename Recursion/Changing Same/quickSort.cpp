#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the rightmost element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement Quick Sort using recursion
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Explicitly use the vector constructor to initialize the array
    std::vector<int> arr = std::vector<int>{10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Given array is: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array is: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
