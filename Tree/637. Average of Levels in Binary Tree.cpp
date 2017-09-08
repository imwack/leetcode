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
    vector<double> ret;
    vector<double> averageOfLevels(TreeNode* root) {
        //层次遍历
        queue<TreeNode*> q;
        if(root==nullptr) return ret;
        q.push(root);
        double sum=0;
        int count=0;
        TreeNode *tail=root,*head;
        while(!q.empty()){
            head = q.front();
            if(head->left) q.push(head->left);
            if(head->right) q.push(head->right);
            if(tail==head){
                tail = q.back();
                ret.push_back(sum/count);
            }else{
                sum+=head->val;
                count++;
            }
            q.pop();    //出队列
        }
        return ret;
    }
};