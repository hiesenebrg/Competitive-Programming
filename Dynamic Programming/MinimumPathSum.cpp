#include <bits/stdc++.h> 
int minSumPathHelper(vector<vector<int>> &grid, int n, int i, int j,vector<vector<int>> &dp) {
    if(i==0 && j==0) return grid[i][j];
    if(i<0 ||  j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int left  = grid[i][j] + minSumPathHelper(grid, n, i,j-1,dp);
    int up  = grid[i][j] + minSumPathHelper(grid, n, i-1,j,dp);
    return dp[i][j] = min(left ,up);
   
}
int minSumPath(vector<vector<int>> &grid) {
   int n = grid.size();
    int m = grid[0].size();
   
   vector<vector<int>>dp(n,vector<int>(m,-1));
    // minSumPathHelper(grid, n, n-1 ,m-1,dp);
    for( int i =0;i<n;i++){
        for( int j =0;j<m;j++){
             if(i==0 && j==0) dp[i][j] =  grid[i][j];
             else{
                int left = grid[i][j]; 
                if(j>0) left  = left + dp[i][j-1];
                else left += 1e9;
                int up  =grid[i][j];
                if(i>0) up  = up + dp[i-1][j];
                else up += 1e9;
                dp[i][j] = min(left ,up);  
             }
        
    } 
    }
    return dp[n-1][m-1];
}
