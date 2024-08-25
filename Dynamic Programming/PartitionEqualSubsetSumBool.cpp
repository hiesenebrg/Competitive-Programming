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


bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	if(sum%2) return false;
	int target = sum/2;
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	return subsetSumToKHelper(n-1,target, arr,dp);
}
