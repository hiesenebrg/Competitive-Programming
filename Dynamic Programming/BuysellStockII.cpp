#include<bits/stdc++.h>

long getMaximumProfitHelper(long *values, int n,int index, bool buy,vector<vector<long>> &dp){
    if(index==n){
        return 0;
    }
    long profit = 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy){
        profit = -values[index] + getMaximumProfitHelper(values,n,index+1,0,dp);
        long notBuying = getMaximumProfitHelper(values,n,index+1,1,dp);
        profit = max(profit, notBuying);

    }
    else{
        profit = values[index] + getMaximumProfitHelper(values,n,index+1,1,dp);
        long notSelling = getMaximumProfitHelper(values,n,index+1,0,dp);
        profit = max(profit, notSelling);
    }
    return dp[index][buy] = profit;
}

long getMaximumProfit(long *values, int n) {
// -->memoiation
    // vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    // return getMaximumProfitHelper(values,n,0,1,dp)

// --- > tabulation
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for(int index = n - 1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                // Buying: Either buy the stock or skip
                profit = max(-values[index] + dp[index + 1][0], dp[index + 1][1]);
            } else {
                // Selling: Either sell the stock or hold
                profit = max(values[index] + dp[index + 1][1], dp[index + 1][0]);
            }
            dp[index][buy] = profit;
        }
    }
    
    return dp[0][1];



// --> greedy
//    long sum = 0;
//     for(int i=1;i<n;i++){
//         if (values[i] >= values[i-1]) sum += (values[i] - values[i-1]) ;
//         else sum+=0;
//     }
        
//     return sum;
}
