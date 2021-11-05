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
vector<int> nums;

void pre(TreeNode * root , string s)
{
    if (!root)
        return;
    
    if (!root->left and !root->right) {
        s += to_string(root->val);
        nums.push_back(stoi(s));
        return;
    }
    
    s += to_string(root->val);
    pre(root->left, s);
    pre(root->right, s);
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        nums.clear();
        pre(root, "");
        int ans = 0;
        for (int x : nums) {
            // cout << x << endl;
            ans += x;
        }
        return ans;
    }
};
