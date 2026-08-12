/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode findStart(TreeNode root, int startValue) {
        if (root == null)
            return null;
        if (root.val == startValue)
            return root;
        TreeNode left = findStart(root.left, startValue);
        if (left != null)
            return left;
        return findStart(root.right, startValue);
    }

    // ONLY THIS PART IS COPIED
    boolean dfs(TreeNode root, TreeNode previous, int destValue,StringBuilder s, HashMap<TreeNode, TreeNode> nodeToParent) {
        if (root == null)
            return false;
        if (root.val == destValue)
            return true;
        // Move UP
        TreeNode parent = nodeToParent.get(root);
        if (parent != null && parent != previous) {
            s.append('U');
            if (dfs(parent, root, destValue, s, nodeToParent))
                return true;
            s.deleteCharAt(s.length() - 1);
        }

        // Move LEFT
        if (root.left != null && root.left != previous) {
            s.append('L');
            if (dfs(root.left, root, destValue, s, nodeToParent))
                return true;
            s.deleteCharAt(s.length() - 1);
        }

        // Move RIGHT
        if (root.right != null && root.right != previous) {
            s.append('R');
            if (dfs(root.right, root, destValue, s, nodeToParent))
                return true;
            s.deleteCharAt(s.length() - 1);
        }

        return false;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder s = new StringBuilder();
        // boolean includes = new boolean[2];
        // includes
        HashMap<TreeNode, TreeNode> nodeToParent = new HashMap<>();
        Queue<TreeNode> q = new LinkedList();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left != null) {
                nodeToParent.put(node.left, node);
                q.offer(node.left);
            }
            if (node.right != null) {
                nodeToParent.put(node.right, node);
                q.offer(node.right);
            }
        }
        TreeNode startNode = findStart(root, startValue);
        dfs(startNode, null, destValue, s, nodeToParent);

        // System.out.println(startNode.val);
        return s.toString();
    }
}