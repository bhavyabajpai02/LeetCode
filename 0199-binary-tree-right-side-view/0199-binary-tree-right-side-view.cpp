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
    void traverse(TreeNode* root,int lvl , vector<int>&res){
        if(!root) return ;
        if(lvl == res.size()){
            res.push_back(root->val);
        }
        traverse(root->right,lvl+1,res);
        traverse(root->left,lvl+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> res;
        // if(!root){
        //     return {};
        // }
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int r , n=q.size();
        //     for(int i=0 ; i<n ; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         r = node->val;
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     res.push_back(r);
        // }
        // return res;
        int lvl = 0;
        vector<int>res;
        traverse(root,lvl,res);
        return res;
    }
};