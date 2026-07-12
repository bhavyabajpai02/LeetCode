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
    vector<int>arr;
    void traverse(TreeNode* root){
        if(!root) return ;
        arr.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        traverse(root);
        TreeNode* ptr = root;
        ptr->left = nullptr;
        for(int i=1; i<arr.size() ; i++){
            ptr->right = new TreeNode(arr[i]);
            ptr = ptr->right;  
        }
    }
};