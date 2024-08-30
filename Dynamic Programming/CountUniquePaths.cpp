#include <bits/stdc++.h>
int uniquePathsHelper(int m, int n,vector<vector<int>> &dp) {
	if(m==0 && n==0) return 1;
	if(m<0 || n<0) return 0;
	if(dp[m][n]!=-1) return  dp[m][n];
	int left  = uniquePathsHelper(m,n-1,dp);
	int up = uniquePathsHelper(m-1, n,dp);
	return dp[m][n] = left+up;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	// return uniquePathsHelper(m-1, n-1,dp);
	
	for( int i=0;i<m;i++){
	for( int j=0;j<n;j++){
		if(i==0 && j==0)  dp[i][j]=1;
		else{
			int left = 0;
			int up = 0;
			if(j>0) left = dp[i][j-1];
			if(i>0) up = dp[i-1][j];
			dp[i][j] = left+up;
		}
		
	}	
	}
	return dp[m-1][n-1];
}
