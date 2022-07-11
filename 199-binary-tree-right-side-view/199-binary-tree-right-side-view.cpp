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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        TreeNode* ele;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                ele = q.front();
                
                if(i==s-1)
                    ans.push_back(ele->val);
                if(ele->left)
                    q.push(ele->left);
                if(ele->right)
                    q.push(ele->right);
                q.pop();
            }
        }
        return ans;
    }
};