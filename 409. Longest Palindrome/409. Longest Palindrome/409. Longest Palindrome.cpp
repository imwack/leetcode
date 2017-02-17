// 409. Longest Palindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int longestPalindrome(string s) {
	int len = 'z' - 'A' + 1;
	int *dic = new int[len];
	bool one = 0;
	int count = 0;
	memset(dic, 0, sizeof(int)*len);
	for (int i = 0; i<s.length(); i++){
		if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z'))
			dic[s[i] - 'A']++;
	}
	for (int i = 0; i<len; i++){
		if (!one && dic[i] % 2 == 1)
			one = 1;
		if (dic[i] >= 2)
			count += (dic[i] % 2 == 0 ? dic[i] : dic[i] - 1);
	}
	return one ? count + 1 : count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez";
	longestPalindrome(s);
	return 0;
}

