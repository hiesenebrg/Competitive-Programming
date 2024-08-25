#include <iostream>
#include <vector>
using namespace std;
bool subsetSumToKHelper(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (n == 0)
        return (arr[n] == k);
    if (dp[n][k] != -1)
        return dp[n][k];
    bool notPick = subsetSumToKHelper(n - 1, k, arr, dp);
    bool pick = false;
    if (k >= arr[n])
        pick = subsetSumToKHelper(n - 1, k - arr[n], arr, dp);
    return dp[n][k] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    // vector<vector<int>>dp(n,vector<int>(k+1,0));
    // return subsetSumToKHelper(n-1,k,arr,dp);
    for( int i=0;i<n;i++) dp[i][0] = true;
    for( int i=0;i<n;i++){
        if(dp[0][n] == k)  dp[0][n] = true;

    }
    for( int i =1;i<n;i++){
        for ( int j=1;j<=k;j++){
            bool notPick = dp[i-1][j];
            bool pick = false;
            if(j>=arr[i]) pick = dp[i-1][j-arr[i]];
             dp[i][j] = pick | notPick;
        }
    }
    return dp[n-1][k];
    
}