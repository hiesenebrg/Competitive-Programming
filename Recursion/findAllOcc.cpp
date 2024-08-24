// #include <iostream>

// using namespace std;

// void findIndices(int arr[], int n, int x, int index, int* count, int* result) {
//     if (index == n) {
//         return;
//     }

//     if (arr[index] == x) {
//         result[*count] = index;
//         (*count)++;
//     }

//     findIndices(arr, n, x, index + 1, count, result);
// }

// int main() {
//     int arr[] = {1, 2, 3, 2, 4, 2, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 2;
//     int count = 0;
//     int result[100]; // Assuming maximum 100 occurrences

//     findIndices(arr, n, x, 0, &count, result);

//     for (int i = 0; i < count; i++) {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
// using vector
#include <iostream>
#include <vector>

using namespace std;

vector<int> findIndices(int arr[], int n, int x) {
    if (n == 0) {
        return vector<int>(); // Create an empty vector
    }

    vector<int> smallAns = findIndices(arr + 1, n - 1, x);
    if (arr[0] == x) {
        smallAns.insert(smallAns.begin(), 0);
    }
    return smallAns;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    vector<int> indices = findIndices(arr, n, x);

    for (int i : indices) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
