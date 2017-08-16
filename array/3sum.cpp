// 3sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<sstream>
#include<string>
using namespace std;


// TLE  用unique太慢
vector<vector<int>> threeSum0(vector<int>& nums) {
	vector<vector<int>> ret;
	if (nums.size() < 3) return ret;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-2;i++){
		int target = -nums[i];
		int l = i + 1, r = nums.size() - 1;
		while (l<r)
		{
			if (nums[l] + nums[r] == target){
				vector<int> temp(3);
				temp[0] = nums[i];
				temp[1] = nums[l];
				temp[2] = nums[r];
				++l; --r;
				ret.push_back(temp);
			}
			else if (nums[l] + nums[r] < target)
				++l;
			else
				--r;
		}
	}
	//去重。。
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	if (nums.size() < 3) return ret;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++){
		int target = -nums[i];
		int l = i + 1, r = nums.size() - 1;
		while (l<r)
		{
			if (nums[l] + nums[r] == target){
				vector<int> temp(3);
				temp[0] = nums[i];
				temp[1] = nums[l];
				temp[2] = nums[r];
				++l; --r;
				while (l<r && nums[l]==nums[l-1])	//hack here
				{ 
					++l;
				} 
				while (l<r && nums[r+1]==nums[r])
				{
					--r;
				}
				ret.push_back(temp);
			}
			else if (nums[l] + nums[r] < target)
				++l;
			else
				--r;
		}
		while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
			i++;
	}
	return ret;
}



int main() {
	vector<int> v = { -1, 0, 1, 2, -1, -4 };


	auto ret = threeSum(v);
	for (auto re : ret){
		for (auto r : re)
			cout << r << '\t';
		cout << endl;	
	}
	return 0;
}