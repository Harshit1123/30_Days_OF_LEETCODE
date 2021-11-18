Simple and easy DFS Solution.






public class Solution {
    int total = 0;
    public int sumNumbers(TreeNode root) {
        if (root == null){
            return 0;
        }
        total(root, String.valueOf(root.val));
        return total;
    }
    
    private void total(TreeNode node, String current){
        if (node.left == null && node.right==null){
            total = total + Integer.parseInt(current);
        }
        else {
            if (node.left!=null){
                total(node.left, current + String.valueOf(node.left.val));
            }
            if (node.right!=null){
                total(node.right,  current + String.valueOf(node.right.val));
            }
        }
    }
}
