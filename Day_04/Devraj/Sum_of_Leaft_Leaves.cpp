class Solution {
public:
    void sum(TreeNode* root,int seperator,int &ans)
    { if(root==NULL)
        return;
     
     if(root->left==NULL && root->right==NULL && seperator==1) //Seperator 1 for left & 2 for right//
         ans+=root->val;
     
     sum(root->left,1,ans);
     sum(root->right,-1,ans);
        
        
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        sum(root,2,ans);  //Passed seperator 2 because we don't want to add root in ans
        return ans;
    }
};
