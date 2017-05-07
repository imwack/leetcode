/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/
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
    bool subtree(TreeNode* s, TreeNode* t) {
        if(t==nullptr ) if(s==nullptr)return true;else return false;
        if(s&& s->val==t->val)
            return subtree(s->left,t->left) && subtree(s->right,t->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s!=NULL){
            bool ret = subtree(s,t);
            if(ret) return true;
            if(s->left) ret=isSubtree(s->left,t);
            if(ret) return true;
            if(s->right) ret=isSubtree(s->right,t);
            if(ret) return true;
        }
        return false;
    }
};