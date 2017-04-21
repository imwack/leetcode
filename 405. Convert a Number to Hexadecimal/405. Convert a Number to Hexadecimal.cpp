// 405. Convert a Number to Hexadecimal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include<iostream>
using namespace std;
string toHex(int num) {
	int count = 0;
	if (!num) return "0";
	string result;
	while (num && count < 8)
	{
		int temp = num & 15;
		if (temp<10)    result.push_back('0' + temp);
		else result.push_back('a' + temp - 10);
		num = num >> 4;
		count++;
	}
	reverse(result.begin(), result.end());
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = -26;
	cout << toHex(num);
	return 0;
}

