class Solution {
public:
    int numTrees(int n) {
         /*  So to get NumTrees At (N) it's a combination of Number of Combination by putting [1..........N] numbers as root.
         *  NumTrees or G[3] = F[1, 3] + F[2, 3] + F[3,3]    where F is a function F(i=currentRoot, N=TotalNodes)
         
         *  General Formula:
         *  F(i, n) = G(i-1) * G(n-i).
         */
        if (n <= 1) return 1;
        vector<int>G(n+1,0);
        G[0] = 1;
        G[1] = 1; // Base Case

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    
        
    }
};
