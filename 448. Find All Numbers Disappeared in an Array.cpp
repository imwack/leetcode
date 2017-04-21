// 448. Find All Numbers Disappeared in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	int flag = -4396;   //dont ask me why
	vector<int> ret;
	int len = nums.size();
	for (int i = 0; i<len; i++){
		while (nums[i] != flag && nums[i] != i - 1){
			if (nums[i] - 1 >= 0 && nums[i] - 1 < len){
				if (nums[i] != nums[nums[i] - 1]){
					swap(nums[i], nums[nums[i] - 1]);
				}
				else{
					nums[i] = flag;
					break;
				}
			}
				
		}

	}
	for (int i = 0; i<len; i++){
		if (nums[i] == flag)
			ret.push_back(i + 1);
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> nums(a, a + 8);
	findDisappearedNumbers(nums);
	return 0;
}

