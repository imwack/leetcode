/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> next(nums.size(),-1);
        stack<int> s;
        for(int i=0;i<nums.size();i++){
             //stack 非空 每次比较当前元素是否比栈顶的大
            while(!s.empty() && nums[i]>nums[s.top()]){ //比栈顶的大 出栈 置位
                next[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);  //stack 放的是元素下标
        }
        for(int i=0;i<nums.size();i++){  //需要将栈中剩下的元素再遍历一圈。。
            while(!s.empty() && nums[i]>nums[s.top()]){
                next[s.top()] = nums[i];
                s.pop();
            }
        }

        return next;
    }
};