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
private:
    void build(TreeNode* root, vector<vector<int>>& res , int level){
        if(!root){
            return;
        }
        if(res.size() < level+1){
            res.push_back({});
        }
        res[level].push_back(root->val);
        build(root->left , res , level+1);
        build(root->right , res , level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       build(root,res,0);
       for(int i=0 ; i<res.size() ; i++){
            if(i%2 !=0){
                reverse(res[i].begin(),res[i].end());
            }
       }
       return res;
    }
};