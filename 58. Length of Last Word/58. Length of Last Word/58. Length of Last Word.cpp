// 58. Length of Last Word.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int lengthOfLastWord(string s) {
	istringstream in(s);
	string str;
	int len = 0;
	while (in >> str){
		cout << str << endl;
		len = str.size();
	}
	return len;
}

int _tmain(int argc, _TCHAR* argv[])
{
	lengthOfLastWord("hello word asd !");
	return 0;
}

