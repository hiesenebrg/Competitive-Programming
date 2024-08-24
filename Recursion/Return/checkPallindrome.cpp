#include <iostream>
#include <string>
using namespace std;

bool checkPallindrome(string str, int s, int e)
{
    if (s >= e)
    {

        return true;
    }
    return str[s] == str[e] && checkPallindrome(str, s + 1, e - 1);
}
int main()
{
    string s;
    cin >> s;
    bool ans = checkPallindrome(s, 0, s.size() - 1);
    cout << ans << endl;
}