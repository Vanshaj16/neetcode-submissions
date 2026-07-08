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
    int dfs(TreeNode* root,int l,int r){
        if(!root){
            return 0;
        }
        l=1+dfs(root->left,l,r);
        r=1+dfs(root->right,l,r);
        return max(l,r);
    }
    int maxDepth(TreeNode* root) {
        int res=dfs(root,0,0);
        return res;
    }
};
