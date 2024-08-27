#include <bits/stdc++.h> 
int maximumChocolatesHelper(int r, int c, vector<vector<int>> &grid, int i, int j1, int j2,vector<vector<vector<int>>> &dp) {
    if(j1<0 || j2<0 || j1>=c|| j2>=c) return -1e8;
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2] ;
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi = 0;
    for(int dj1 =-1;dj1<2;dj1++){
        for(int dj2 =-1;dj2<2;dj2++){
          
            if(j1==j2) maxi = max(maxi,grid[i][j1] + maximumChocolatesHelper(r,c,grid,i+1,j1+dj1,j2+dj2,dp)) ;
            else maxi = max(maxi ,grid[i][j1] + grid[i][j2]  + maximumChocolatesHelper(r,c,grid,i+1,j1+dj1,j2+dj2,dp));
    }
    }
    return dp[i][j1][j2] =  maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return maximumChocolatesHelper(r,c,grid,0,0,c-1,dp);
}
//https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
