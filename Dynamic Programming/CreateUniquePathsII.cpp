int mod = (int)(1e9 +7);

int uniquePathsHelper(int m, int n,vector< vector< int> > &mat,vector<vector<int>> &dp) {
	if(m==0 && n==0) return 1;
    if(m>=0 && n>=0 && mat[m][n]== -1) return 0;
	if(m<0 || n<0) return 0;
	if(dp[m][n]!=-1) return  dp[m][n];
	int left  = uniquePathsHelper(m,n-1,mat,dp);
	int up = uniquePathsHelper(m-1, n,mat,dp);
	return dp[m][n] = (left+up)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   vector<vector<int>>dp(n,vector<int>(m,-1));
	return uniquePathsHelper(n-1, m-1,mat,dp);
}
