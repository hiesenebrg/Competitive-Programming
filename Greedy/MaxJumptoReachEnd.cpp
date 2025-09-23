// Jump Game - 1
bool canReachAtEnd(vector<int> &arr,int n){
    int maxIndex = 0;
    if(arr[0]==0) return false;
    for( int i=0;i<n;i++){
        if(i>maxIndex) return false;
        if(i+arr[i]>maxIndex) maxIndex = i+arr[i];
    }
    return true;
}

// Jump Game - 2
int recursiveImpl(vector<int> &arr,int index,vector<int> &dp){
    if(index>=arr.size()-1) return 0;
    if(dp[index]!=-1) return dp[index];
    int mini = 1e8;
    for(int i= 1;i<=arr[index];i++){
        mini = min(mini,1+recursiveImpl(arr,index+i,dp));
    }
    return dp[index] = mini;
}