// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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

