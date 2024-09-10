#include <bits/stdc++.h>
using namespace std;
//dp
int getMaximumProfitHelper(vector<int>& values, int n, int index, bool buy, int cap, vector<vector<vector<int>>> &dp) {
    if (index == n || cap == 0) {
        return 0;
    }

    if (dp[index][buy][cap] != -1) return dp[index][buy][cap];

    int profit = 0;
    if (buy) {
        // Option 1: Buy the stock
        int buyStock = -values[index] + getMaximumProfitHelper(values, n, index + 1, 0, cap, dp);
        // Option 2: Do nothing (skip buying)
        int skipBuy = getMaximumProfitHelper(values, n, index + 1, 1, cap, dp);
        profit = max(buyStock, skipBuy);
    } else {
        // Option 1: Sell the stock
        int sellStock = values[index] + getMaximumProfitHelper(values, n, index + 1, 1, cap - 1, dp);
        // Option 2: Do nothing (skip selling)
        int skipSell = getMaximumProfitHelper(values, n, index + 1, 0, cap, dp);
        profit = max(sellStock, skipSell);
    }

    return dp[index][buy][cap] = profit;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    

// --> memoiation
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); 
    // return getMaximumProfitHelper(prices, n, 0, 1, k, dp);

// -->tabulation


    if (n == 0) return 0;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
    
    // dp[n][buy][cap] is initialized to 0 for all values of buy and cap, which makes sense
    // because on or after the last day, no profit can be made.

    for (int index = n - 1; index >= 0; index--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy) {
                    // Buying: Either buy the stock or skip buying
                    int buyStock = -prices[index] + dp[index + 1][0][cap];
                    int skipBuy = dp[index + 1][1][cap];
                    dp[index][buy][cap] = max(buyStock, skipBuy);
                } else {
                    // Selling: Either sell the stock or skip selling
                    int sellStock = prices[index] + dp[index + 1][1][cap - 1];
                    int skipSell = dp[index + 1][0][cap];
                    dp[index][buy][cap] = max(sellStock, skipSell);
                }
            }
        }
    }

    return dp[0][1][k];
}
