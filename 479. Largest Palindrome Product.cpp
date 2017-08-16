// 479. Largest Palindrome Product.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<math.h>
#include<iostream>
#include<string>

using namespace std;

long long to_sum(int left){
	string temp = to_string(left);
	reverse(temp.begin(), temp.end());
	long long sum = stoll(to_string(left)+temp);
	return sum;

}
int largestPalindrome(int n) {
	if (1 == n) return 9;
	int left = pow(10, n) - 1; //99..
	while (left>0){
		long long sum = to_sum(left);
		for (long long x = pow(10, n) - 1; x*x >= sum; x--){
			if (sum%x == 0 && (sum / x) <= x){
				return sum % 1337;
			}
		}
		left--;
	}
	return 0;

}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<largestPalindrome(8);
	return 0;
}

