#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function to find all subsets that sum to k
void findSubsets(int idx, int k, vector<int>& arr, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    // Base case: if k is 0, we've found a valid subset
    if (k == 0) {
        allSubsets.push_back(currentSubset);
        return;
    }

    // If we've gone through all elements or k is negative, return
    if (idx >= arr.size() || k < 0) return;

    // Exclude the current element and move to the next
    findSubsets(idx + 1, k, arr, currentSubset, allSubsets);

    // Include the current element in the subset and recurse
    currentSubset.push_back(arr[idx]);
    findSubsets(idx + 1, k - arr[idx], arr, currentSubset, allSubsets);

    // Backtrack: remove the current element from the subset
    currentSubset.pop_back();
}

// Function to find and return all subsets that sum to k
vector<vector<int>> subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<int>> allSubsets;
    vector<int> currentSubset;
    findSubsets(0, k, arr, currentSubset, allSubsets);
    return allSubsets;
}
