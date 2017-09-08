/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/



vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> pos(2,-1);
    if(!binary_search(nums.begin(),nums.end(),target)) return pos;
    auto it1 = lower_bound(nums.begin(),nums.end(),target);
    pos[0] = ( it1 - nums.begin() );
    auto it2 = upper_bound(nums.begin(),nums.end(),target);
    pos[1] = ( it2 - nums.begin() -1 );
    return pos;
}
/* ____________________________________________________________*/
int lowerBound(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1,mid;
    while(l<=r){
        mid = (r-l)/2+l;
        if(nums[mid]>=target) r=mid-1;
        else l=mid+1;
    }
    return l;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> pos(2,-1);
    if(nums.size()<1) return pos;
    int start = lowerBound(nums,target);
    int end = lowerBound(nums,target+1)-1;
    cout<<start<<'\t'<<end<<endl;
    if(start<nums.size()){
        if(nums[start]!=target && start+1<nums.size()) start++;
        if(nums[start]==target){
            pos[0] = start;
            pos[1] = end;
        }
    }
    return pos;
}
/* _______________________STL_____________________________________*/
int lowerBound(vector<int>& nums, int target) {
    int len=nums.size(),mid,half,first=0;
    while(len>0){
        half = len>>1;
        mid = first + half;
        if(nums[mid]<target){
            first = mid+1;
            len = len-half-1;
        }else{
            len = half;
        }
    }
    return first;
}