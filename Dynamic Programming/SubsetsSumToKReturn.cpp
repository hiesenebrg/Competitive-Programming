#include <iostream>
#include <vector>
using namespace std;

// Function to find all subsets that sum to k using space optimization
void findSubsets(int n, int k, vector<int>& arr, vector<vector<bool> >& dp, vector<int>& currentSubset, vector<vector<int> >& allSubsets) {
    if (k == 0) {
        allSubsets.push_back(currentSubset);
        return;
    }
    if (n == 0) return;

    if (dp[n][k]) {
        findSubsets(n-1, k, arr, dp, currentSubset, allSubsets);
    }
    if (k >= arr[n] && dp[n][k-arr[n]]) {
        currentSubset.push_back(arr[n]);
        findSubsets(n-1, k-arr[n], arr, dp, currentSubset, allSubsets);
        currentSubset.pop_back();
    }
}

// Function to find and return all subsets that sum to k
vector<vector<int> > subsetSumToK(int n, int k, vector<int>& arr) {
    // Use a 1D array to store the current row of DP values
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    
    // Base case: A subset with sum 0 is always possible (by choosing no elements)
    prev[0] = true;

    // Initialize the first row
    if (arr[0] <= k) prev[arr[0]] = true;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        curr[0] = true;  // Subset with sum 0 is always possible
        for (int j = 1; j <= k; j++) {
            bool notPick = prev[j];
            bool pick = false;
            if (j >= arr[i]) pick = prev[j-arr[i]];
            curr[j] = pick || notPick;
        }
        prev = curr;  // Move to the next row
    }

    // If there's no subset with the sum k, return an empty vector<vector<int> >
    if (!prev[k]) return vector<vector<int> >();

    // Reconstruct the solution using the previous row
    vector<vector<int> > allSubsets;
    vector<int> currentSubset;
    
    // Convert 1D DP to 2D for tracing subsets (we could optimize further but keeping it clear here)
    vector<vector<bool> > dp(n, vector<bool>(k + 1));
    dp[0] = prev;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = curr[j];
        }
    }

    findSubsets(n-1, k, arr, dp, currentSubset, allSubsets);

    return allSubsets;
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    int n = arr.size();
    int k = 9;

    vector<vector<int> > subsets = subsetSumToK(n, k, arr);

    if (subsets.empty()) {
        cout << "No subset with sum " << k << " exists." << endl;
    } else {
        cout << "Subsets with sum " << k << " are:" << endl;
        for (auto& subset : subsets) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
