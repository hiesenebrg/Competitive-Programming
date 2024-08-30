#include <bits/stdc++.h> 

int mod = (int)(1e9 + 7);
int findWaysHelper(vector<int>& arr, int k, int n,vector<vector<int>> &dp)
{
	
	// if(k==0) return  1;
        if (n == 0) {
			if(k==0 && arr[0]==0) return 2;
			if(k==0 || arr[0] == k) return 1;
			 return 0;
        }
       
        if(dp[n][k]!=-1) return dp[n][k];
	int take = 0;
	if(arr[n]<=k) take = findWaysHelper(arr,k-arr[n],n-1,dp);
	int notTake = findWaysHelper(arr,k,n-1,dp);
	return dp[n][k] = (take+notTake)%mod;
}


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return findWaysHelper(arr,k,arr.size()-1,dp);
}




int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
   for(auto &itr:arr) sum+=itr;
   if(sum-d<0 || (sum-d)%2) return false;
   else return findWays(arr,(sum-d)/2);
}


