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
    TreeNode* dfs(unordered_map<int,int>& mp,vector<int>& preorder,int& idx,int left,int right){
        if(left>right) return NULL;
        int root_val=preorder[idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = mp[root_val];
        root->left = dfs(mp,preorder,idx,left,mid-1);
        root->right = dfs(mp,preorder,idx,mid+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode();
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        return dfs(mp,preorder,idx,0,inorder.size()-1);
    }
};
