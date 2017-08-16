
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.


*/
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount+1, -1);
	dp[0] = 0;
	for (int c : coins) 
		if(c<=amount)
			dp[c] = 1;
	for (int i = 1; i < amount + 1; i++) {
		int minT = INT_MAX;
		for (int j = 0; j < coins.size(); j++) {
			if (i > coins[j] && dp[i - coins[j]]!=-1) {
				minT = min(minT,dp[i - coins[j]] + 1);
			}
		}
		if (minT < dp[i] || dp[i] == -1)
			dp[i] = minT==INT_MAX?-1:minT;
	}
	return dp[amount];
}
int main()

{
	//[2147483647] 2
	vector<int> coins = { 2 };
	cout<<coinChange(coins, 3);
    return 0;
}

