/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;
void dfs(vector<string> &ret, string temp, int cur, int len, int curL, int L, int R) {
	if (cur == len) {
		ret.push_back(temp);
		return;
	}
	if (curL>0) { //已经有左括号了
		if (L>0) { //还有左括号
			temp.push_back('(');
			dfs(ret, temp, cur + 1, len, curL + 1, L - 1, R);
			temp.pop_back();
			if (R>0) {
				temp.push_back(')');
				dfs(ret, temp, cur + 1, len, curL - 1, L, R - 1);
				temp.pop_back();
			}
		}
		else {//没有左括号了
			temp.push_back(')');
			dfs(ret, temp, cur + 1, len, curL - 1, L, R - 1);
		}

	}
	else { //没有左括号 只能插左括号
		temp.push_back('(');
		dfs(ret, temp, cur + 1, len, curL + 1, L - 1, R);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ret;
	string temp;
	dfs(ret, temp, 0, 2*n, 0, n, n);
	return ret;
}

int main()
{
	vector<string> ret = generateParenthesis(3);
	for (auto s : ret)
		cout << s << endl;
    return 0;
}

