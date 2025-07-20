#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> hmap;  // A map to store the frequency of each element in the array
    int arr[] = { 1, 2, 4, 3, 2, 3, 4, 43, 2 };  // Input array

    // Loop through the array and count the frequency of each element
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++)
    {
        hmap[arr[i]]++;  // Increment the count for arr[i] in the map
    }

    // Use an iterator to print the frequency of each element
    map<int, int>::iterator it;
    for (it = hmap.begin(); it != hmap.end(); it++)
    {
        cout << it->first    // integer (key)
             << " --> "
             << it->second   // frequency (value)
             << endl;
    }

    // Alternatively, using a range-based for loop
    // for (auto it : hmap)
    // {
    //     cout << it.first << "-->" << it.second << endl;
    // }
}