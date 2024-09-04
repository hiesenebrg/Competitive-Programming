#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minEle = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();i++){    
        profit  = max(profit, prices[i]-minEle);
        minEle = min(minEle, prices[i]);
    }
    return profit;
}
