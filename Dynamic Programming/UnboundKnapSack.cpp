
#include <bits/stdc++.h> 

int knapsackHelper(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> &dp) 
{
	if(n==0){
	 return ((int)(maxWeight/weight[0]))*value[0];
		
	}
	if( dp[n][maxWeight]!=-1) return  dp[n][maxWeight];
	int notPick  =  knapsackHelper(weight,value,n-1,maxWeight,dp);
	int pick = 0;
	if(weight[n]<=maxWeight) pick = value[n] +  knapsackHelper(weight,value,n,maxWeight-weight[n],dp);
	return dp[n][maxWeight] =  max(pick,notPick);
}



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
	int maxWeight = w;
// --> Memoization
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
	// return knapsackHelper(weight,profit,n-1,w,dp);

// --> Tabulation
    

		// vector<vector<int>>dp(n,vector<int>(w+1,0));

		//     for( int ws=0;ws<=maxWeight;ws++) dp[0][ws] =  ((int)(ws/weight[0]))*profit[0];

		// 	for( int i=1;i<n;i++){
		// 		for( int j=0;j<=maxWeight;j++){
			
		// 		int notPick  =  dp[i-1][j];
		// 		int pick = 0;
		// 		if(weight[i]<=j) pick = profit[i] + dp[i][j-weight[i]];
		// 		dp[i][j] =  max(pick,notPick);
		// 		}
		// 	}	
			
		//  return dp[n-1][maxWeight];

// ---> 1D Array Space Optimization which take 2 arrays

		//  vector<int> prev(maxWeight+1,-1) ,curr(maxWeight+1,-1);
  
		//     for( int ws=0;ws<=maxWeight;ws++) prev[ws] =  ((int)(ws/weight[0]))*profit[0];
		// 	for( int i=1;i<n;i++){
		// 		for( int j=0;j<=maxWeight;j++){
			
		// 		int notPick  =  prev[j];
		// 		int pick = 0;
		// 		if(weight[i]<=j) pick = profit[i] + curr[j-weight[i]];
		// 		curr[j] =  max(pick,notPick);
		// 		}
		//         prev = curr;
		// 	}	
			
		//  return prev[maxWeight];

// ---> 1D Array Space Optimization which take 1 arrays


 vector<int> prev(maxWeight+1,-1);
  
    for( int ws=0;ws<=maxWeight;ws++) prev[ws] =  ((int)(ws/weight[0]))*profit[0];
	for( int i=1;i<n;i++){
		for( int j=0;j<=maxWeight;j++){
	
		int notPick  =  prev[j];
		int pick = 0;
		if(weight[i]<=j) pick = profit[i] + prev[j-weight[i]];
		prev[j] =  max(pick,notPick);
		}
	}	
	
 return prev[maxWeight];
}
