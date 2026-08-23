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
    void inorder(TreeNode* root,vector<TreeNode*>& arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root,arr);

        TreeNode* node1=NULL;
        TreeNode* node2=NULL;

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]->val > arr[i+1]->val){
                node2=arr[i+1];
                if(!node1) node1=arr[i];
            }
        }
        swap(node1->val,node2->val);
    }
};