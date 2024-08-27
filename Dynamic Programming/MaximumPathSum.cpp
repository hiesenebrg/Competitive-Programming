#include <bits/stdc++.h>

int getMaxPathSumHelper(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& dp) {
    if (j < 0 || j >= matrix[0].size()) {
        return -1e8; 
    }
    if (i == 0) {
        return matrix[0][j];
    }
    if(dp[i][j]!=-1) return dp[i][j]; 
   
    int down = matrix[i][j] + getMaxPathSumHelper(matrix,i -1, j,dp);
    int leftDiagonal = matrix[i][j] + getMaxPathSumHelper(matrix, i - 1, j - 1,dp);
    int rightDiagonal = matrix[i][j] + getMaxPathSumHelper(matrix, i - 1, j + 1,dp);

    // Return the maximum of the three paths
    return dp[i][j] = max(down, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>>& matrix) {
    int maxi = -1e8;
    int n  = matrix.size();
    int m= matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    // for( int k =0;k<matrix[0].size();k++){
    //     maxi = max(maxi,getMaxPathSumHelper(matrix, matrix.size()-1,k,dp));
    // }
     for( int j=0;j<m;j++) dp[0][j] = matrix[0][j];
     for( int i=1;i<n;i++){
        for( int j =0;j<m;j++){
            int down = matrix[i][j] + dp[i-1][j];
            int leftDiagonal  = matrix[i][j];
            if(j>0) leftDiagonal+= dp[i-1][j-1];
            else leftDiagonal += -1e8;
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal+=dp[i-1][j+1];
            else rightDiagonal += -1e8;
            dp[i][j] = max(down, max(leftDiagonal, rightDiagonal));
        }
    }
    for( int k =0;k<m;k++){
        maxi = max(maxi,dp[n-1][k]);
    }
    return maxi  ;
}

// https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
