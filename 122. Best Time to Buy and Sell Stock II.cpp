// 122. Best Time to Buy and Sell Stock II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 0)
		return 0;
	int minPrice = prices[0];
	int totalProfit = 0;
	int maxProfit = 0;
	for (int i = 1; i<prices.size(); i++){
		if (prices[i]<prices[i-1]){
			minPrice = prices[i];
			//sell
			totalProfit += maxProfit;
			maxProfit = 0;
		}
		else maxProfit = prices[i] - minPrice;
	}
	return totalProfit + maxProfit;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1,2, 3, 2, 4, 1, 5 }; 

	vector<int> prices(a, a+sizeof(a) / sizeof(int));
	cout<<maxProfit(prices);
	return 0;
}

