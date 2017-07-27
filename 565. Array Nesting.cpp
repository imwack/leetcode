class Solution {
public:

    int arrayNesting(vector<int>& nums) {
        int maxCount = 0;
        for(int k=0;k<nums.size();k++){
            int count = 0;

            while(nums[k]>=0 && nums[k]<nums.size()){
                count++;
                k = nums[k];
                nums[k] = -1;
            }
            maxCount = count>maxCount?count:maxCount;
        }
        return maxCount;
    }
};