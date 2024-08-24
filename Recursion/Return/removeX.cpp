#include <iostream>
#include <string>
using namespace std;

string removeX(string str, char x) {
    if (str.empty()) {
        return "";
    }
    if (str[0] == x) {
        return removeX(str.substr(1), x);
    } else {
        return str[0] + removeX(str.substr(1), x);
    }
}

int main() {
    string s;
    cin >> s;
    cout << "The answer after removeX is: " << removeX(s, 'x') << endl;
    return 0;
}
