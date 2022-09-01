/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        preorder(root,count,INT_MIN);
        return count;
    }
    
    void preorder(TreeNode* root, int &count, int m){
        if(!root)
            return;
        preorder(root->left,count,max(m,root->val));
        //do
        if(root->val>=m)
            count++;
        preorder(root->right,count,max(m,root->val));
    }
};