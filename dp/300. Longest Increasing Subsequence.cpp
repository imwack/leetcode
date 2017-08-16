#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
300. Longest Increasing Subsequence
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given[10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up : Could you improve it to O(n log n) time complexity ?

len =1	2	3	4
	2	3	7	18
*/

//n^2
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size(),1);
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxLen = 0;
	for (int i = 0; i < nums.size(); i++)
		maxLen = max(dp[i], maxLen);
	return maxLen;
}

//nlogn
int lengthOfLIS2(vector<int>& nums) {
	vector<int> minQueue;
	int curLen = 0, maxLen = 0;
	for (int i = 0; i < nums.size();i++){
		auto it = lower_bound(minQueue.begin(), minQueue.end(), nums[i]);
		if (it == minQueue.end()) minQueue.push_back(nums[i]);
		else *it = nums[i];
	}
	return minQueue.size();
}

int main()

{

	vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
	cout << lengthOfLIS2(nums) << endl;
    return 0;
}

