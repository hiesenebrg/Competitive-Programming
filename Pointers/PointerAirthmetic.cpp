#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // Accessing array elements using pointer arithmetic
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Element " << i << ": " << *(ptr + i) << std::endl;
    }

    // Incrementing the pointer
    ptr++;
    std::cout << "After incrementing, the value at the new pointer location: " << *ptr << std::endl;

    // Decrementing the pointer
    ptr--;
    std::cout << "After decrementing, the value at the original pointer location: " << *ptr << std::endl;

    // Adding an offset to the pointer
    int offset = 2;
    ptr += offset;
    std::cout << "After adding an offset of " << offset << ", the value at the new pointer location: " << *ptr << std::endl;

    // Subtracting an offset from the pointer
    ptr -= offset;
    std::cout << "After subtracting an offset of " << offset << ", the value at the original pointer location: " << *ptr << std::endl;

    int num = 10;
    int* ptr2 = &num;

    // Incrementing the pointer
    ptr2++;
    std::cout << "After incrementing, the value at the new pointer location: " << *ptr2 << std::endl;

    // Decrementing the pointer
    ptr2--;
    std::cout << "After decrementing, the value at the original pointer location: " << *ptr2 << std::endl;

    // Adding an offset to the pointer
    int offset2 = 2;
    ptr2 += offset2;
    std::cout << "After adding an offset of " << offset2 << ", the value at the new pointer location: " << *ptr2 << std::endl;

    // Subtracting an offset from the pointer
    ptr2 -= offset2;
    std::cout << "After subtracting an offset of " << offset2 << ", the value at the original pointer location: " << *ptr2 << std::endl;
    
    return 0;
}