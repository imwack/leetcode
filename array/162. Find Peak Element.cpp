/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r-1){
            int m = l+(r-l)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            if(nums[m+1]>nums[m] && nums[m]>nums[m-1])
                l = mid+1;
            else
                r = mid-1;
        }
        return nums[l]>nums[r]?l:r;
    }
};

