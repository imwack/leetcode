/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        int lhs=0,temp;
        for(int n:nums) m[n]++;
        auto it=m.begin();
        int pre=it->first, pre_count=it->second;
        if(it!=m.end()) ++it;
        for(;it!=m.end();++it){
            if(it->first==pre+1){
                temp=it->second + pre_count;
                if(temp>lhs) lhs=temp;
            }
            pre=it->first, pre_count=it->second;
        }
        return lhs;
        
    }
};