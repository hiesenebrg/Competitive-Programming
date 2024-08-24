#include <iostream>
#include <vector>
using namespace std;
int frogJumpMemoization(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = frogJumpMemoization(n - 1, heights, dp) + abs(heights[n - 1] - heights[n]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpMemoization(n - 2, heights, dp) + abs(heights[n - 2] - heights[n]);
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    //   vector<int>dp(n,-1);
    // dp[0] = 0;
    //  frogJumpMemoization(n-1, heights,dp);
    // for( int i =1;i<n;i++){
    //   int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
    //   int ss = INT_MAX;
    //   if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);
    //   dp[i] = min(fs,ss);

    // }
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}