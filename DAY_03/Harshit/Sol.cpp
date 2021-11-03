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
    void strings(TreeNode* root,vector<string> &vec,string &s)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            s += to_string(root->val);
            vec.push_back(s);
            s.pop_back();
            return;
        }
        s += to_string(root->val);
        strings(root->left,vec,s);
        strings(root->right,vec,s);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        string s = "";
        strings(root,v,s);
        int ans = 0;
        for(auto s:v)
        {
            stringstream str(s);
            int x = 0;
            str >> x;
            ans += x;
        }
        return ans;
    }
};
