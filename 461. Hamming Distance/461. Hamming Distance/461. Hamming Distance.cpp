// 461. Hamming Distance.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int hammingDistance(int x, int y) {
	int dif = x^y;
	int count = 0;
	while (dif != 0){
		dif = dif &(dif - 1);
		count++;
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<hammingDistance(1, 4);
	return 0;
}

