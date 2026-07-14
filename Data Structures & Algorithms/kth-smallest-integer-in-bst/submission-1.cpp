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
    void dfs(TreeNode* node,int& ans,int& cnt,int k){
        if(!node) return;
        dfs(node->left,ans,cnt,k);
        cnt++;
        if(cnt==k){
            ans=node->val;
        }
        dfs(node->right,ans,cnt,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0, cnt=0;
        dfs(root,ans,cnt,k);
        return ans;
    }
};
