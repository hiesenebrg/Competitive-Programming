#include <stack>
#include <string>
using namespace std;

bool isOperand(char c) {
    return isalnum(c); // checks if c is a letter or digit
}

string postToInfix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isOperand(c)) {
            s.push(string(1, c)); // push operand as string
        } else {
            // Operator: pop two operands
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }

    return s.top(); // final infix expression
}
