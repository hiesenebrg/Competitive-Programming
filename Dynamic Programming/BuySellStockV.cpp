#include<bits/stdc++.h>

int getMaximumProfitHelper(vector<int> &values, int n,int index, bool buy,vector<vector<int>> &dp){
    if(index>=n){
        return 0;
    }
    int profit = 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy){
        profit = -values[index] + getMaximumProfitHelper(values,n,index+1,0,dp);
        int notBuying = getMaximumProfitHelper(values,n,index+1,1,dp);
        profit = max(profit, notBuying);

    }
    else{
        profit = values[index] + getMaximumProfitHelper(values,n,index+2,1,dp);
        int notSelling = getMaximumProfitHelper(values,n,index+1,0,dp);
        profit = max(profit, notSelling);
    }
    return dp[index][buy] = profit;
}


int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n +1, vector<int>(2, -1));
    return getMaximumProfitHelper(prices,n,0,1,dp);
}
