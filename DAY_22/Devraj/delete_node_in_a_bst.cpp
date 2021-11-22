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
    TreeNode* InorderSuc(TreeNode* root)
    { while(root->left)
        root=root->left;
      return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        if(root->val==key)
           {    
               if(root->left==NULL && root->right==NULL)           //Node Having 0 Child
                    return NULL;
            
               if(root->left && root->right)                       //Node Having 2 Child
                {
                 TreeNode * temp=InorderSuc(root->right);
                 root->val=temp->val;
                 
                 root->right=deleteNode(root->right,temp->val);
                 return root;
               }
               if(root->right)                                    //Node Having 1 Child
                 return root->right;
               if(root->left)                                        //Node Having 1 Child
                return root->left;
         }
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);
        return root;
    }
};
