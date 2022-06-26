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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        vector<vector<int>>res;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                auto ele=q.front();
                temp.push_back(ele->val);
                q.pop();
                if(ele->left)
                    q.push(ele->left);
                if(ele->right)
                    q.push(ele->right);
            }
            res.push_back(temp);
            
        }
        return res;
    }
};