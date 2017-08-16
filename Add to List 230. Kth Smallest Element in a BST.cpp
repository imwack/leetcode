/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int result=0;
    void PreOrder(TreeNode* root, int &k){
        if(root==nullptr || 0==k) return;
        if(root->left) PreOrder(root->left,k);

        --k;
        if(0==k) result = root->val;

        if(root->right) PreOrder(root->right,k);
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        PreOrder(root,&k);
        return result;
    }
};