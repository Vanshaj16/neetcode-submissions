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
    vector<vector<int>> res;
    void dfs(TreeNode* node,int idx){
        if(!node) return;
        if(res.size()==idx){
            res.push_back(vector<int>());
        }
        res[idx].push_back(node->val);
        dfs(node->left,idx+1);
        dfs(node->right,idx+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        return res;
    }
};
