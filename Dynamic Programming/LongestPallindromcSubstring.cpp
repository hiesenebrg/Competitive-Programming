#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    string str1 = s;
    reverse(str1.begin(),str1.end());
    int m = s.size();
    int n = str1.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == str1[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    
    return dp[m][n];
}
