#include <iostream>
#include <vector>
using namespace std;
int maximumNonAdjacentSumHelper(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
        return nums[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int fs = nums[n] + maximumNonAdjacentSumHelper(nums, n - 2, dp);
    int ss = maximumNonAdjacentSumHelper(nums, n - 1, dp);
    return dp[n] = max(fs, ss);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    // return maximumNonAdjacentSumHelper(nums, nums.size()-1,dp);
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for (int i = 2; i < dp.size(); i++)
    {

        int fs = nums[i] + dp[i - 2];
        int ss = dp[i - 1];
        dp[i] = max(fs, ss);
    }
    return dp[nums.size() - 1];
}