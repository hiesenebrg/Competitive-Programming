#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcs(string &str1, string &str2)
{
    int m = str1.size();
    int n = str2.size();

    // Create a 2D DP array initialized to 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0; // To store the length of the longest common substring

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0; // Reset the length if characters don't match
            }
        }
    }

    return maxLength; // The length of the longest common substring
}