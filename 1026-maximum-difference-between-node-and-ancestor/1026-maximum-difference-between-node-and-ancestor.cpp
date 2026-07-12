class Solution {
public:
    int res = 0;

    void traverse(TreeNode* root, int mn, int mx){
        if(!root) return;

       

        mn = min(mn, root->val);
        mx = max(mx, root->val);
        res = max(res, max(abs(root->val - mn), abs(root->val - mx)));

        traverse(root->left, mn, mx);
        traverse(root->right, mn, mx);
    }

    int maxAncestorDiff(TreeNode* root) {
        traverse(root, root->val, root->val);
        return res;
    }
};