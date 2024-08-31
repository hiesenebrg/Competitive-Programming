#include <iostream>
#include <vector>
using namespace std;

int cutRodHelper(vector<int> &price, int n, int length,vector<vector<int>> &dp)
{
	if(n==0){
		return  length*price[0];
	}
	if(dp[n][length]!=-1) return dp[n][length];
	int notTake =  cutRodHelper(price ,n-1,length,dp);
	 
	int take = INT_MIN;
	int rodLength = n+1;
	if(rodLength<=length) take  =  price[n]  + cutRodHelper(price ,n,length - rodLength,dp);
	return dp[n][length] = max(take, notTake);
}


int cutRod(vector<int> &price, int n) {
	// vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// return cutRodHelper(price, n-1,n,dp);
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; j++) 
        dp[0][j] = j * price[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            int notTake = dp[i-1][j];  // Corrected to i-1 to stay within bounds
            int take = INT_MIN;
            int rodLength = i + 1;
            if (rodLength <= j) 
                take = price[i] + dp[i][j - rodLength];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}
