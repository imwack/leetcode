/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

class Solution {
public:

class TreeNode {
public:
	TreeNode* next[2];
	TreeNode() { next[0] = NULL; next[1] = NULL; };
};
void BuildTree(TreeNode *root, int x){
	TreeNode *p = root;
	for (int i = 31; i>=0; i--){
		int flag = (x >> i) & 1;
		if (root->next[flag] == nullptr){
			root->next[flag] = new TreeNode();
		}
		root = root->next[flag];
	}
}
int FindMaxXor(TreeNode *root, int x){
	int ret = 0;
	for (int i = 31; i >= 0; i--){
		int flag = 1-(x>>i)&1;
		ret <<= 1;
		if (root->next[flag] != nullptr){
			ret |= 1;
			root = root->next[flag];
		}
		else {
			ret |= 0;
			root = root->next[1 - flag];
		}
	}
	return ret;
}
int findMaximumXOR(vector<int>& nums) {
	TreeNode* head = new TreeNode();
	for (int n : nums){
		BuildTree(head, n);
	}
	int m = 0;
	for (int n : nums){
		int ret = FindMaxXor(head, n);
		m = max(m, ret);
	}
	return m;
}
};
