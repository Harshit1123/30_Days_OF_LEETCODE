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
//-------------------------------- O(n) Time Complexity Solution --------------------------//
class Solution {
public:
     unordered_map<int,int>mp;
     TreeNode* build(vector<int>& P,int &currI,int s,int e)
       { if(e>s)
          return NULL;
     
       TreeNode* root=new TreeNode(P[currI]);
       int mid=mp[P[currI]];
       currI--;
       root->right=build(P,currI,s,mid+1);
       root->left=build(P,currI,mid-1,e);
        
     return root;   
        
    }
    TreeNode* buildTree(vector<int>& I, vector<int>& P) {
        
      
        for(int i=0;i<I.size();i++)
            mp[I[i]]=i;                  //Here we store index of element from Inorder,So that we can find Index in O(1)time 
        int currI=P.size()-1;
        return build(P,currI,P.size()-1,0);
        
    }
};
