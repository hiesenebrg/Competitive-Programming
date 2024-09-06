#include<bits/stdc++.h>

int longestIncreasingSubsequenceHelper(int ind, int prev,int arr[], int n, vector<vector<int>> &dp)
{
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int ans = 0+ longestIncreasingSubsequenceHelper(ind+1, prev, arr,n,dp);
    if(prev==-1 || arr[ind]>arr[prev]){
        ans = max(ans, 1+longestIncreasingSubsequenceHelper(ind+1,ind,arr,n,dp));
    }
    return dp[ind][prev+1] =ans;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return longestIncreasingSubsequenceHelper(0,-1,arr,n,dp);
    // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for( int prev=ind-1;prev>=-1;prev--){
            int ans = 0+ next[prev+1];
            if(prev==-1 || arr[ind]>arr[prev])
                ans = max(ans, 1+next[ind+1]);
    
            curr[prev+1] =ans;

        }
      next = curr;
    }
    return next[0];
// ---> most optimised solution

  
  // vector<int> lis;  // This will store the LIS sequence
    
  //   for (int i = 0; i < n; i++) {
  //       // Find the position to replace or extend the LIS
  //       auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        
  //       // If the element is greater than all elements in lis, append it
  //       if (it == lis.end()) {
  //           lis.push_back(arr[i]);
  //       } 
  //       // Otherwise, replace the found position
  //       else {
  //           *it = arr[i];
  //       }
  //   }
  //  return lis.size();
}
