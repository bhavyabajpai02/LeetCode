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
    int maxSum=INT_MIN;
    int currentSum(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = max(0,currentSum(root->left));
        int right = max(0,currentSum(root->right));
        maxSum = max(maxSum,root->val+left+right);
        return root->val+ max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        currentSum(root);
        return maxSum;
    }
};