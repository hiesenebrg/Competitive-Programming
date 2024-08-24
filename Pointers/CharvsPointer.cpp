#include <iostream>
using namespace std;
int main()
{
    char ch = 'A';
    char *ptr = &ch;

    cout << "Character: " << ch << endl;
    cout << "Pointer: " << ptr << endl;
    // differnce between char array  and int array

    int a[] = {1, 2, 3, 4, 5};
    char b[] = "Hello";
    cout << "Value of a: " << a << endl; // This will print the address of the first element of the array
    cout << "Value of b: " << b << endl; // This will print the string "Hello"
    char *p = &b[0];
    cout << "Value of p: " << p << endl; // This will print the string "Hello"

// never use string like this, always make an char array
    char *psrt = "Adarsh";
    cout << "Value of psrt: " << &psrt << endl; // This will print the string "Adarsh"

    return 0;
}