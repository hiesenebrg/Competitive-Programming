#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // vector<int> dp(nums.size(),-1);
    int prev = nums[0];
    int prev2 = 0;
    for( int i=1;i<nums.size();i++){
    int take = nums[i];
    if(i>1) take+=prev2;
    int notTake = prev;
   
    int curr = max(take,notTake);
    
    prev2 = prev;
    prev = curr;
  }
  return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
   vector<int>wf(n-1);
    vector<int>wl(n-1);
    if(n==1) return valueInHouse[0];
    for(int i =0;i<n;i++){
        if(i!=0) wf.push_back(valueInHouse[i]);
        if(i!=n-1) wl.push_back(valueInHouse[i]);
    }
        return max(maximumNonAdjacentSum(wf),maximumNonAdjacentSum(wl));
}
