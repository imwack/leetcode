// 290. Word Pattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include <sstream>  
using namespace std;
 
bool wordPattern(string pattern, string str) {
	unordered_map<string,char> map;
	istringstream in(str);

	for (int i = 0;  i<pattern.length(); i++){
		string word;
		in >> word;
		cout << word << endl;
		char c = pattern[i];
		if (word.length() == 0) return false;
		unordered_map<string,char>::iterator it = map.find(word);
		if (it != map.end()){
			if (it->first != word)
				return false;
		}
		else{
			//if (word.length() == 0) return false;
			pair<string,char> p( word,c);
			map.insert(p);
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string pattern = "jquery";
	string str = "jquery";
	cout<<wordPattern(pattern, str);
	return 0;
}

