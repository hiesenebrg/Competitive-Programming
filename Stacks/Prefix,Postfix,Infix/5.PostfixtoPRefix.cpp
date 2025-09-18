#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postToPrefix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(string(1, c)); // operand as string
        } else if (isOperator(c)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string expr = c + op1 + op2; // prefix: operator + operand1 + operand2
            s.push(expr);
        }
    }

    return s.top(); // final prefix expression
}
