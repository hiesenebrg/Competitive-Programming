#include <stack>
#include <string>
using namespace std;

bool isOperand(char c)
{
    return isalnum(c); // checks if c is a letter or digit
}

string prefixToInfixConversion(string &s)
{
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isOperand(c))
        {
            st.push(string(1, c)); // push operand as string
        }
        else
        {
            // Operator: pop two operands
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    return st.top(); // final infix expression
}
