#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> maxSubarraySum(vector<int> &arr) {
    int res = arr[0];           
    int maxEnding = arr[0];     
    int start = 0, end = 0, s = 0;

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(arr[i], maxEnding + arr[i]);

        if (maxEnding == arr[i]) {
            s = i; // Start a new subarray
        }

        if (maxEnding > res) {
            res = maxEnding;
            start = s; // Update start index
            end = i;   // Update end index
        }
    }

    // Extract the maximum subarray
    vector<int> maxSubarray(arr.begin() + start, arr.begin() + end + 1);
    return {res, maxSubarray};
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubarraySum(arr);
    
    cout << "Maximum Subarray Sum: " << result.first << endl;
    cout << "Elements of the Maximum Subarray: ";
    for (int num : result.second) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}