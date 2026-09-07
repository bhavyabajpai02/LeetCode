class Solution {
    void getLeaves(TreeNode root, ArrayList<Integer> list) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            list.add(root.val);
            return;
        }
        getLeaves(root.left, list);
        getLeaves(root.right, list);
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        getLeaves(root1, a);
        getLeaves(root2, b);
        return a.equals(b);
    }
}