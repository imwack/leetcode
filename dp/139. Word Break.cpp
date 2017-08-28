/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> m;
        for (string word : wordDict) {
            m.insert(word);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 0; i<=s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string str = s.substr(j, i - j);
                    if (m.find(str) != m.end()) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};