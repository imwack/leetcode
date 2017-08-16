// Unique Paths.cpp : �������̨Ӧ�ó������ڵ㡣
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

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n,0));
	for (int i = 0; i < n; ++i){
		dp[0][i] = 1;
	}
	for (int i = 0; i < m; ++i){
		dp[i][0] = 1;
	}
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m-1][n-1];
}

//���ϰ��İ汾
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	if (obstacleGrid[0][0] == 1) return 0; //����ж�
	dp[0][0] = 1;
	for (int i = 1; i < n; ++i){  
		if (obstacleGrid[0][i - 1] != 1 && obstacleGrid[0][i] != 1) //��ߺ��Լ�����1
				dp[0][i] = dp[0][i-1];
	}
	for (int i = 1; i < m; ++i){
		if (obstacleGrid[i - 1][0] != 1 && obstacleGrid[i][0] != 1) //�ϱߺ��Լ�����1
				dp[i][0] = dp[i-1][0];
	}
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; ++j){
			if (obstacleGrid[i][j]!=1) //�Լ�����1����
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}
int main() {
	//cout<<uniquePaths(5, 10);
	vector<vector<int>> obstacleGrid;
	
	obstacleGrid.push_back(vector<int>()={ 0, 1, 0, 0, 0 });
	obstacleGrid.push_back(vector<int>() = { 1, 0, 0, 0, 0 });
	obstacleGrid.push_back(vector<int>() = { 0, 0, 0, 0, 0 });
	obstacleGrid.push_back(vector<int>() = { 0, 0, 0, 0, 0 });
	cout<<uniquePathsWithObstacles(obstacleGrid);
	return 0;
}