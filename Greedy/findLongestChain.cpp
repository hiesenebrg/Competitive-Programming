class Solution {
    vector<int> t;
public:
    int getNext(vector<vector<int>>& pairs, int l, int end){
        int r = pairs.size() - 1;
        int result = r + 1;
        while(l <= r){
            int mid  = l + (r-l)/2;
            if(pairs[mid][0] > end){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
    }