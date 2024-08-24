#include <iostream>

int main() {
    int value = 42;
    int* ptr = &value;
    int** doublePtr = &ptr;

    std::cout << "Value: " << value << std::endl;
    std::cout << "Pointer value: " << *ptr << std::endl;
    std::cout << "Double pointer value: " << **doublePtr << std::endl;

    return 0;
}