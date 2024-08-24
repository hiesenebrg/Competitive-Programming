#include <iostream>
using namespace std;
double xpowern(int n, int x)
{
    if (n == 1)
    {
        return x;
    }
    return x * xpowern(n - 1, x);
}
int main()
{
    int n, x;
    cout << "Enter the x"<<endl;
    cin >> x;
    cout << "Enter the n"<<endl;

    cin >> n;
    double ans = xpowern(n, x);
    cout << "the ans is " << ans << endl;
    return 0;
}