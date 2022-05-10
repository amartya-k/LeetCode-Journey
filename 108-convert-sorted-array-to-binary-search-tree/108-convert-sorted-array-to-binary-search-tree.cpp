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
    TreeNode* sortedArrayToBST(vector<int>& v) {
        return buildTree(v,0,v.size()-1);
        
        
    }
    
    TreeNode* buildTree(vector<int>& v,int start, int end){
        if(start>end)
            return NULL;
        
        int mid =(start+end)/2;
        TreeNode*root = new TreeNode(v[mid]);
        root->left = buildTree(v,start,mid-1);
        root->right = buildTree(v,mid+1,end);
        
        return root;
        
        
    }
    
    
};
/*
[-10,-3,0,5,9]
[-10,-3]  [5,9]
[-3]  [9]



*/