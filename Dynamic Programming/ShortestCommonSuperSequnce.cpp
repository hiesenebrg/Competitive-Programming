#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // Build the DP table for LCS
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";
    int i = m, j = n;

    // Backtrack through the DP table to construct the shortest supersequence
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            ans += b[j - 1];
            j--;
        } else {
            ans += a[i - 1];
            i--;
        }
    }

    // Add remaining characters from a and b
    while (i > 0) {
        ans += a[i - 1];
        i--;
    }
    while (j > 0) {
        ans += b[j - 1];
        j--;
    }

    // Reverse the result string since we built it backwards
    reverse(ans.begin(), ans.end());

    return ans;
}
