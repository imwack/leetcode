/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

int search(vector<int>& nums, int target) {
    if(nums.size()<1) return -1;
    //binary search
    int l=0,r=nums.size()-1,mid;

    while(l<r){
        mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        if(nums[l]<=nums[mid]){ //左边是递增的
            if(nums[mid]>target && nums[l]<=target){ //中间的大于目标
                r=mid-1;
            }else{
                l=mid+1;
            }
        }else{ //右边递增
            if(nums[mid]<target && nums[r]>=target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
    }

    return nums[l]==target?l:-1;
}