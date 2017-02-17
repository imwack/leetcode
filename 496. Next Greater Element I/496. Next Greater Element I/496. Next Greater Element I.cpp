// 496. Next Greater Element I.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	vector<int> ret;
	if (findNums.size()<1 || nums.size()<1)
		return ret;  //error

	sort(findNums.begin(), findNums.end());
	sort(nums.begin(), nums.end());
	int i = 0, j = 0;
	while (i<findNums.size() && j<nums.size()){
		while (findNums[i] != nums[j]) j++;
		int num = j<nums.size() ? j + 1 : -1;
		ret.push_back(num);
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 4, 1, 2 };
	int b[] = {1, 3, 4, 2};
	vector<int> va(a, a + 3);
	vector<int> vb(b, b + 4);
	nextGreaterElement(va, vb);
	return 0;
}

