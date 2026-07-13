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
    void dfs(TreeNode* node,priority_queue<int,vector<int>,greater<int>>& pq){
        if(!node) return;
        pq.push(node->val);
        if(node->left) dfs(node->left,pq);
        if(node->right) dfs(node->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        dfs(root,pq);
        while(k>1 && !pq.empty()){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
