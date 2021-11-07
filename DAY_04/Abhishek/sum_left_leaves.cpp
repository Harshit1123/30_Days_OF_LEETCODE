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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        
        myFun(root,'c');
        return sum;
        
    }

    void myFun(TreeNode* root ,char c)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
        {   if(c=='l')
          { cout<<root->val<<endl;
            sum+=root->val;
          }  
        }
        
        // if left node is present the go to left not
        if(root->left)
        myFun(root->left,'l');
        
        // if right node is present the go to right not
        if(root->right)
        myFun(root->right,'r');
        //return sum;
        
    }

};
