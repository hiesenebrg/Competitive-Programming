#include <iostream>
using namespace std;
bool isSorteds(int arr[], int n)
{
    if (n == 2)
    {
        if (arr[0] <= arr[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return arr[0] <= arr[1] && isSorteds(arr + 1, n - 1);
}
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return isSorted(arr + 1, n - 1);
}
int firstindex(int arr[], int n, int k, int i)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == k)
    {
        return i;
    }
    return firstindex(arr + 1, n - 1, k, i + 1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)

    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    bool values = isSorted(arr, n);
    bool dvalues = isSorteds(arr, n);
    int index = firstindex(arr, n, 4, 0);
    
    cout << "The values is " << values << endl;
    cout << "The values is " << dvalues << endl;
    cout << "The index is " << index << endl;

    return 0;
}
