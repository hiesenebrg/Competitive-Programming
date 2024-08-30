#include<bits/stdc++.h>
int ninjaTrainingHelper(int n, vector<vector<int>> &points, int index, int task,vector<vector<int>> &dp)
{
  if(n==0){
      int maxi  = 0;
      for( int  i=0;i<task;i++){
          if(i!=index){
              maxi =max(points[0][i], maxi);
          }
      }
      return maxi;
  }  
  if(dp[n][index]!=-1) return dp[n][index];
  int maxi = 0;
  for( int i =0; i<task;i++){
      int point = 0;
      if(i!=index){ 
           point = points[n][i] + ninjaTrainingHelper(n-1,points,i,task,dp);
      maxi = max(maxi, point);
      }
  }
  return dp[n][index] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4,-1));
     return ninjaTrainingHelper(n-1, points,3 ,3,dp);
}