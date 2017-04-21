// 67. Add Binary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string addBinary(string a, string b) {
	if (a.size()<1) return b;
	if (b.size()<1) return a;
	int len1 = a.size() - 1;
	int len2 = b.size() - 1;
	int carry = 0;
	string sum;
	while (len1 >= 0 || len2 >= 0 || carry){
		carry += len1 >= 0 ? a[len1] : 0;
		carry += len2 >= 0 ? b[len2] : 0;
		sum += carry % 2 + '0';
		carry /= 2;
		len1--; len2--;
	}
	reverse(sum.begin(), sum.end());
	return sum;

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

