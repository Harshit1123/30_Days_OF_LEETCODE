class Solution {
public:
  //   -----------------Recursive with memoization----------------//
  //     int path(int m,int n,  vector<vector<int>>&dp){
  //          if(m==0 || n==0) return 1;
  //          if(dp[m][n]!=-1)
  //             return dp[m][n];
  //           return dp[m][n]=path(m-1,n,dp) + path(m,n-1,dp);
  //         }
  //     int uniquePaths(int m, int n) {
  //         vector<vector<int>>dp(m,vector<int>(n,-1));
  //         return path(m-1,n-1,dp);
  //     }
    
      // -------------Iterative DP(Bottom Up DP)----------------More optimized//
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {  if(i==0 || j==0)
                 dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
            }
        }
    return dp[m-1][n-1];
    }
    
