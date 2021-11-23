class Solution {
public:
    int numTrees(int n) {
        long long dp[n+1] ;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;      
    
    for(long long i = 2; i <= n; i++){            
        long long l = 0, r = (i - 1);            
        while( l <= (i - 1) ) {
            dp[i] += dp[l] * dp[r];
            l++;
            r--;
        }            
    }
    return dp[n];
}
};
