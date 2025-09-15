#include<iostream>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min = INT_MIN;
        int maxi = 0;
        int num=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==min){
                min = nums[i];
                num++;
            }else if(nums[i]==min){
                continue;
            }else{
                num=1;
                min = nums[i];
            }
            maxi = max(num,maxi);
        }
        return maxi;
    }
};