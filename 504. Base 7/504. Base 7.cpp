// 504. Base 7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string convertToBase7(int num) {
	string str;
	if (num >= 0){
		while (num != 0){
			str += num % 7 + '0';
			num /= 7;
		}

	}
	else{
		num = -num;
		while (num != 0){
			str += num % 7 + '0';
			num /= 7;
		}
		num += '-';

	}
	reverse(str.begin(), str.end());
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = -7;
	cout<<convertToBase7(num);
	return 0;
}

