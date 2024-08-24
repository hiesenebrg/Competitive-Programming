#include <iostream>

using namespace std;

int lengthOfString(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return 1 + lengthOfString(str + 1);
}

void removeX(char str[], char x)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == x)
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i];
        removeX(str, x);
    }
    else
    {
        removeX(str + 1, x);
    }
}
int main()
{
    char str[] = "hello";
    int len = lengthOfString(str);
    
    cout << "Length of the string: " << len << endl;
    removeX(str,'l');
    cout << "after remove char: " << str << endl;
    return 0;
}


// using string
// #include <iostream>
// #include <string>

// using namespace std;

// string removeX(string str) {
//     if (str.empty()) {
//         return "";
//     }

//     if (str[0] == 'x') {
//         return removeX(str.substr(1));
//     } else {
//         return str[0] + removeX(str.substr(1));
//     }
// }

// int main() {
//     string str = "axbxcx";
//     string result = removeX(str);
//     cout << result << endl;
//     return 0;
// }
