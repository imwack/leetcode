// 最长回文子串.cpp : 定义控制台应用程序的入口点。
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

string longestPalindrome(string s) {
	//manacher
	string str = "#";
	for (auto ss : s) str = str + ss + "#"; //preprocess
	vector<int> P(str.size(), 0);

	int R=0,C=0; //index为对称中心，R=len(index)+index
	for (int i = 1; i < str.size()-1; ++i){
		int mirror_i = 2 * C - i;  //i 关于C的对称点
		if (R < i) P[i] = 0;
		else P[i] = min(R - i, P[mirror_i]);

		while ((i - 1 - P[i] >=0)&&(i+1+P[i]<str.size())&&(str[i + 1 + P[i]] == str[i - 1 - P[i]]))   //往外扩
			P[i]++;
		if (i + P[i]>R){ //update R and C
			C = i;
			R = i + P[i];
		}
	}
	string ret;
	int center = 0, length = 0;
	for (int i = 0; i < P.size();++i)
	if (P[i]>length) {
		length = P[i];
		center = i;
	}
	for (int i = center - length; i < center + length; ++i)
	if (str[i] != '#')
		ret += str[i];

	return ret;
}
int main() {
	string s = "abbbbbacdcab";
	cout<<longestPalindrome(s);
	return 0;
}