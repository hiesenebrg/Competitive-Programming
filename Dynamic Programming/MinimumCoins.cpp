#include <bits/stdc++.h> 

int minimumElementsHelper(vector<int> &num, int x, int n,vector<vector<int>> &dp)
{
    if(n==0){
        if(x%num[0]==0) return x/num[0];
        else return 1e9;
    }
    if(dp[n][x]!=-1) return dp[n][x];
    int pick = INT_MAX;
    if(num[n]<=x) pick = 1 + minimumElementsHelper(num, x-num[n],n,dp);
    int notPick = 0+ minimumElementsHelper(num, x,n-1,dp);
    return dp[n][x] =  min(pick, notPick);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    //   vector<vector<int>>dp(n,vector(x+1,-1));
    //    int ans =  minimumElementsHelper(num, x, n-1,dp);
    //    if(ans>=1e9) return -1;
    //    else return ans;
    vector<vector<int>>dp(n,vector(x+1,0));

   for( int i =0;i<=x;i++){
       if(i%num[0]==0) dp[0][i] = i/num[0];
       else dp[0][i] = 1e9;
   }
   for( int i =1;i<n;i++){
      for( int j =0;j<=x;j++){
            int pick = INT_MAX;
            if(num[i]<=j) pick = 1 + dp[i][j-num[i]];
            int notPick = 0 + dp[i-1][j];
            dp[i][j] =  min(pick, notPick);
   } 
   }

    if(dp[n-1][x]>=1e9) return -1;
    else return dp[n-1][x];
}
