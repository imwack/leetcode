// 506. Relative Ranks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


vector<string> findRelativeRanks(vector<int>& nums) {
	vector<int> rank;
	vector<string> ret(nums.size());
	for (int i = 0; i < nums.size(); i++)
		rank.push_back(i);
	sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b]; });

	for (int i = 0; i<nums.size(); i++){
		ret[rank[i]] = to_string(i+1);
	}

	if (rank.size()>0)
		ret[rank[0]] = ("Gold Medal");
	if (rank.size()>1)
		ret[rank[1]] = ("Silver Medal");
	if (rank.size()>2)
		ret[rank[2]] = ("Bronze Medal");

	return ret;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 5, 3, 2, 1 };
	vector<int> vec(a, a + 5);

	vector<string> ret = findRelativeRanks(vec);
	for (auto i : ret)
		cout << i << endl;
	return 0;
}

