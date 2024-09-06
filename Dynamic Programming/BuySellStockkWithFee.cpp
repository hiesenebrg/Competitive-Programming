#include<bits/stdc++.h>

int getMaximumProfitHelper(vector<int> &values, int n,int fee ,int index, bool buy,vector<vector<int>> &dp){
    if(index>=n){
        return 0;
    }
    int profit = 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy){
        profit = -values[index] + getMaximumProfitHelper(values,n,fee,index+1,0,dp);
        int notBuying = getMaximumProfitHelper(values,n,fee,index+1,1,dp);
        profit = max(profit, notBuying);

    }
    else{
        profit = values[index] - fee + getMaximumProfitHelper(values,n,fee,index+1,1,dp);
        int notSelling = getMaximumProfitHelper(values,n,fee,index+1,0,dp);
        profit = max(profit, notSelling);
    }
    return dp[index][buy] = profit;
}

int maximumProfit(vector<int> &prices, int n, int fee)
{

    vector<vector<int>> dp(n +1, vector<int>(2, -1));
    return getMaximumProfitHelper(prices,n,fee,0,1,dp);
}
