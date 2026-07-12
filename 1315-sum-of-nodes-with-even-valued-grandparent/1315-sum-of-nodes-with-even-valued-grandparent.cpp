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
int res = 0;
    void traverse(TreeNode* root){
        if(!root){
            return ;
        }
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left) res += root->left->left->val;
                if(root->left->right) res += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) res += root->right->left->val;
                if(root->right->right) res += root->right->right->val;
            }
        }
         traverse(root->left);
         traverse(root->right);
        // return root;
    }
    int sumEvenGrandparent(TreeNode* root) {

        traverse(root);
        return res;
    }
};