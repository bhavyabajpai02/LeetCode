/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<bool,bool> dfs(TreeNode* root,TreeNode*p,TreeNode* q,TreeNode** res){
        if(!root) return {false,false};
         auto left = dfs(root->left,p,q,res);
         auto right = dfs(root->right,p,q,res);
        // if( == p ) left.first = true;
        // if(right == p ) right.first = true;
        // if(left == q ) left.second = true;
        // if(right == q ) right.second = true;
        bool contains_p = left.first or right.first or root == p;
        bool contains_q = left.second or right.second or root == q;
        if(contains_p and contains_q and *res == nullptr){
            *res = root; 
        }
        // if((left.first and right.second) or (left.second and right.second)){
            
        // }
        
        // if(root == q){
        //     check.second = true;
        // }
        // if(check.first and check.second and *res == nullptr){
        //     *res = root;
        //     return;
        // }
        return {contains_p,contains_q};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root == p or root == q) return root;
        // pair<bool,bool>check{false,false};
        TreeNode* res = nullptr;
        dfs(root,p,q,&res);
        return res;
    }
};