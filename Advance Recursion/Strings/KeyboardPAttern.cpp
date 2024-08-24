#include <iostream>
using namespace std;
#include <string>
#include <vector>
string pattern(int n)
{
    if (n == 1)
    {
        return "abc";
    }
    if (n == 2)
    {
        return "def";
    }
    if (n == 3)
    {
        return "ghi";
    }
    if (n == 4)
    {
        return "jkl";
    }
}
int returnPattern(int n, string output[])
{
    if (n / 10 == 0)
    {
        output[0] = "";
        return 1;
    }
    int rem = n % 10;
    int i = 0;
    int j = 0;
    int size = 0;
    string str = pattern(rem);

    size = returnPattern(n / 10, output);
    for (; i < str.size(); i++)
    {
        for (; j < size; j++)
        {
            output[i + j + size] = str[i] + output[j];
        }
    }
    return i * j * size;
}

int main()
{
    // string input;
    // cin >> input;
    string *output = new string[1000];
    int n = 23;
    int count = returnPattern(n, output);
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}