// Minimum Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<string>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < n; i++)
		dp[0][i] = grid[0][i]+dp[0][i-1];
	for (int j = 1; j < m; j++)
		dp[j][0] = grid[j][0]+dp[j-1][0];

	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}
int main() {
	vector<vector<int>>  grid;
	//[[1,2,5],[3,2,1]]
	grid.push_back(vector<int>() = { 1, 2, 5 });
	grid.push_back(vector<int>() = { 3,2,1});
	cout<<minPathSum(grid);
	return 0;
}