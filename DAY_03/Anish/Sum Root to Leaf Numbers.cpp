 Sum Root to Leaf Numbers- DAY-3 solution
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
    void trav(TreeNode* root,int num,int &sum)
    {      if(root==NULL ) return;
           		num= num*10+ root->val;
           
           if(root->left==NULL && root->right==NULL)
           		sum+= num;
           
          trav(root->left,num,sum);
          trav(root->right,num,sum);
        
    }
    int sumNumbers(TreeNode* root) 
	{
        int num=0;
        int sum=0;
        trav(root,num,sum);
        return sum;  
    }
};
