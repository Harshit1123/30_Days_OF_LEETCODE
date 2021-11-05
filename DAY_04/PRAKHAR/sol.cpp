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
int ans = 0;

bool leaf(TreeNode * root) {
    return (!root->left and !root->right);
}

void dfs(TreeNode * root, int signal)
{
    if (!root)
        return;
    
    if (signal and leaf(root))
        ans += root->val;
    
    if (root->left)
        dfs(root->left, 1);
    
    if (root->right)
        dfs(root->right, 0);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        dfs(root, 0); // 0 for a signal if its a left node or not
    
        return ans;
    }
};
