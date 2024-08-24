#include <iostream>
using namespace std;

void printN(int n)
{
    if(n == 0)
    {
        return;
    }
    
    printN(n - 1);
    cout << n << endl;
    
    return;
}
int main()
{
    int n;
    cin >> n;
    printN(n);
    return 0;
}