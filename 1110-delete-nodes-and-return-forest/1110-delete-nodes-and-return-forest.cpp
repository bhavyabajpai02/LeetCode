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
    void build (TreeNode*& root , vector<TreeNode*>&v , unordered_set<int>&st){
        if(!root){
            return ;
        }
            build(root->left,v,st);
            build(root->right,v,st);
        if(st.count(root->val)){
            auto it = find(v.begin(),v.end(),root);
            if(it != v.end()){
                v.erase(it);
            }
            if(root->left and !st.count(root->left->val)){
                v.push_back(root->left);
            }
            if(root->right and !st.count(root->right->val)){
                v.push_back(root->right);
            }
                root = nullptr;
                return ;
        }        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(to_delete.empty())return {root};
        vector<TreeNode*> v;
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        v.push_back(root);
        build(root,v,st);
        return v;
    }
};