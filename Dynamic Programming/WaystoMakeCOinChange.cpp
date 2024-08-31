#include <iostream>
#include <vector>
using namespace std;

long minimumElementsHelper(int *denominations, int x, int n,vector<vector<long>> &dp)
{
    if(n==0){
      return (x%denominations[0]==0);
        
    }
    if(dp[n][x]!=-1) return dp[n][x];
    long pick = 0;
    if(denominations[n]<=x) pick =  minimumElementsHelper(denominations, x-denominations[n],n,dp);
    long notPick = 0+ minimumElementsHelper(denominations, x,n-1,dp);
    return dp[n][x] = pick+notPick;
}

    


long countWaysToMakeChange(int *denominations, int n, int value)
{
   
      vector<vector<long>>dp(n,vector<long>(value+1,-1));
      return   minimumElementsHelper(denominations, value, n-1,dp);
       
}
