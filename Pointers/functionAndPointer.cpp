#include <iostream>

// Function that takes a pointer as parameter

void incrementPointerr(int *p)
{
    p = p + 1;
}
void increment(int *p)
{
    *p = *p + 1;
}
int *incrementPointer(int *p)
{
    p = p + 1;
    return p;
}
// int summ(int *arr, int size) we can also replace int arr[] with int *arr
int summ(int arr[], int size)
{
    // here arr is treated as just a  pointer so its size will be 8 bytes instead of 4*5 = 20 bytes
    std::cout << "Size of array in passed func: " << sizeof(arr) << std::endl; // This will print the size of the pointer
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // here arr is treated as array pointer
    std::cout << "Sum of array elements without passsed func: " << sizeof(arr) << std::endl;
    int ans = summ(arr, 5);
    int Forwardedans = summ(arr+2, 3);

    std::cout << "Sum of array elements: " << ans << std::endl;
        std::cout << "Sum of array elements: " << Forwardedans << std::endl;

    int *ptr = arr;

    int num = 10;
    int *ptr2 = &num;
    std::cout << "Value of num: " << ptr2 << std::endl;
    incrementPointerr(ptr2);
    increment(ptr2);
    std::cout << "Value of ptr2: " << ptr2 << std::endl; // value remains same because it will send the copy of the address
    std::cout << "Value of num: " << num << std::endl;   // val+1
    int *ptr3 = incrementPointer(ptr2);
    std::cout << "Value of ptr3: " << ptr3 << std::endl; // val
    return 0;
}