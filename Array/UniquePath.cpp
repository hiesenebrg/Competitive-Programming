#include<iostream>
using namespace std;

class Solution {
public:
    int recursivePaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // Out of bounds
        if (i >= m || j >= n) {
            return 0;
        }
        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        // Already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // Store result in dp table
        dp[i][j] = recursivePaths(i + 1, j, m, n, dp) +
                   recursivePaths(i, j + 1, m, n, dp);
        return dp[i][j];
    }


    int uniquePaths(int m, int n) {
        // dp approach
        vector<vector<int>> dp(m, vector<int>(n, 1));


        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recursivePaths(0, 0, m, n, dp);
    }
};

