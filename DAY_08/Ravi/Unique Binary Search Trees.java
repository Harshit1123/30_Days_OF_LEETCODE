// ## JAVA MEMORIZATION + RECURSION SOLUTION.


class Solution {
    public int trav(int l,int h,int dp[][])
    {
        if(l>h)
            return 0;
        if(l==h)
            return 1;
        if(dp[l][h]!=0)
            return dp[l][h];
        int ans=0;
        for(int i=l;i<=h;i++)
        {
            int left=trav(l,i-1,dp);
            int right=trav(i+1,h,dp);
            if(left==0 || right==0)
                ans=ans+left+right;
            else
                ans=ans+(left*right);  
        }
        dp[l][h]=ans;
        return ans;
    }
    public int numTrees(int n) {
        int dp[][]=new int[n+1][n+1];
        return trav(1,n,dp);
    }
}
