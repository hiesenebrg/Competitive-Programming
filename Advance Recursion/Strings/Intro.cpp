#include <iostream>
#include <string>
using namespace std;
int main()
{
    string inputString;

    // Read a line of input from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Print the input string
    cout << "Input string: " << inputString << endl;
    inputString[0] = 'A';

    cout << "Changed string: " << inputString << endl;
    string additionalstring = " This ends here";
    inputString += additionalstring;
    cout << "Complete string: " << inputString << endl;
    cout << "size of  string: " << inputString.size() << endl;
    cout << "size of  string: " << inputString.length() << endl;
        cout << "sub of  string: " << inputString.substr(3) << endl;
        // here inputString.substr(3,5) means from index 3 to length of 5
        cout << "substr of  string: " << inputString.substr(3,5) << endl;


    return 0;
}