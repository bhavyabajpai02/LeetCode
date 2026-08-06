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
    int preIndex;
    unordered_map<int,int> pos;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd){
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        root->left = build(preorder, inStart, mid - 1);
        root->right = build(preorder, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;

        for (int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};
