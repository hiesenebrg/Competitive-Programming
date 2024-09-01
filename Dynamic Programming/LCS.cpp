#include <iostream>
#include <vector>
using namespace std;

int lcsHelper(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return  dp[i][j];
    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + lcsHelper(s, t, i - 1, j - 1, dp);
    return dp[i][j] = max(lcsHelper(s, t, i - 1, j, dp), lcsHelper(s, t, i, j - 1, dp));
}
int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
    // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    // 	// return  lcsHelper(s,t,s.size(), t.size(),dp);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
