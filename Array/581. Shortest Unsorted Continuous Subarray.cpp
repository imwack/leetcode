
/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ret;
        int ma = *(max_element(nums.begin(),nums.end()));
        int mi = *(min_element(nums.begin(),nums.end()));
        
        int l=0,r=nums.size()-1;
        if(nums.size()>0 && nums[0]==mi){
            l = 0;
            while(l+1<nums.size() && nums[l+1]>=nums[l]) l++;
        }
        if(nums.size()>0 && nums[nums.size()-1]==ma){
            r=nums.size()-1;
            while(r>0 && nums[r]>=nums[r-1]) r--;
        }
        if(l<r){
            ma = INT_MIN, mi=INT_MAX;
            for(int i=l;i<=r;i++){
                if(nums[i]>ma) ma=nums[i];
                if(nums[i]<mi) mi=nums[i];
            }
            while(l>=0 && nums[l]>mi) l--;
            while(r<nums.size() && nums[r]<ma) r++;
            for(int i=l+1;i<r;i++) ret.push_back(nums[i]);
        }
        return ret.size();
        
    }
};