// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Solution.h"


int main()
{
	Solution s;
	vector<vector<int>> vec;
	vec.push_back(vector<int> { 3, 4 });
	vec.push_back(vector<int> { 2, 3 });
	vec.push_back(vector<int> { 1, 2 });

	s.findRightInterval(vec);
}

