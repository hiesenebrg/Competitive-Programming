int BinarySearch(vector<int> &arr, int start, int end, int x){
    int mid = (start + end)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid] == x){
        return mid;
    }
    if(x>arr[mid]){
        return BinarySearch(arr,mid+1,end,x);
    }
    else{
        return BinarySearch(arr,start,mid-1,x);
    }

}
int search(vector<int> &nums, int target) {
    //Write your code here.
    return BinarySearch(nums,0,nums.size()-1,target);
}
