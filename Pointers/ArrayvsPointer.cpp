#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;

    // Accessing array elements
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Accessing pointer elements
    std::cout << "Pointer elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    // Size of array and pointer
    std::cout << "Size of array: " << sizeof(arr) << std::endl;
    std::cout << "Size of pointer: " << sizeof(ptr) << std::endl;


    int *p = &arr[0];
    int *s = arr;
    int*t = &arr[1]; //arr index moves by 4 bytes
    int *u = t+1; //pointer moves by 8 bytes
     std::cout << "Value of p: " << p << std::endl;
        std::cout << "Value of arr: " << arr << std::endl;
        std::cout << "Value of s: " << s << std::endl;
        std::cout << "Value of t: " << t << std::endl;
        std::cout << "Value of u: " << u << std::endl;


    return 0;
}