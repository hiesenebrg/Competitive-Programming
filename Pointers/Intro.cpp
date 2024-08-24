#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int *ptr = &num;

    // Print the value of num
    cout << "Value of num: " << num << endl;

    // Print the address of num
    cout << "Address of num: " << &num << endl;

    // Print the value of ptr (address of num)
    cout << "Value of ptr: " << ptr << endl;

    // Print the value pointed by ptr (value of num)
    cout << "Value pointed by ptr: " << *ptr << endl;

    // Print the size of ptr
    cout << sizeof(ptr) << endl;

    // Increment the value of num
    num++;

    // Print the updated value of num
    cout << "Value of num: " << num << endl;

    // Print the value pointed by ptr (updated value of num)
    cout << "Value pointed by ptr: " << *ptr << endl;

    // Increment the value pointed by ptr
    (*ptr)++;

    // Print the updated value of num
    cout << "Value of num: " << num << endl;

    // Print the value pointed by ptr (updated value of num)
    cout << "Value pointed by ptr: " << *ptr << endl;

    // Example of null pointer
    int *nullPtr = 0;
    // Print the value of nullPtr
    cout << "Value of nullPtr: " << nullPtr << endl;
    // Dereferencing a null pointer will result in undefined behavior
    // Uncomment the line below to see the effect
    cout << "Value pointed by nullPtr: " << *nullPtr << endl;
    return 1;
}