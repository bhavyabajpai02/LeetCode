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
    void goodNodes(TreeNode* root, int maxvalue,int& good){
        if(!root){
            return ;
        }
        if(root->val >= maxvalue){
            maxvalue = root->val;
            good++;
        }
        goodNodes(root->left,maxvalue,good);
        goodNodes(root->right,maxvalue,good);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxvalue = INT_MIN, good = 0;
        goodNodes(root,maxvalue,good);
        return good;

    }
};