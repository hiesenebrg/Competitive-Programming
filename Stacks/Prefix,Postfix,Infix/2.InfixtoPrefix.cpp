#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
// it is same as infinxtoPostfix, just reverse the string
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(const string& exp) {
    stack<char> s;
    string result;

    for (char c : exp) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Pop '('
        } else {
            // Operator
            while (!s.empty() && s.top() != '(' &&
                   ((isRightAssociative(c) && precedence(s.top()) > precedence(c)) ||
                    (!isRightAssociative(c) && precedence(s.top()) >= precedence(c)))) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

// reverse at the end to get correct prefix
    reverse(result.begin(), result.end());
    return result;
    return result;
}
