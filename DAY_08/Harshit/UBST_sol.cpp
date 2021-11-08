class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        vector<int> c1 (n, 0);
        vector<int> c2 (n, 0);
        
        c1[1] = 1;
        int sum = 1;
        for(int i = 3; i <= n; i++) {
            c2[1] = sum;
            int sum2 = sum;
            for(int j = 2; j < i; j++) {
                sum -= c1[j-2];
                c2[j] = sum;
                sum2 += sum;
            }
            sum = sum2;
            c1 = c2;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += c1[i] * (i+1);
        }
        return ans;
    }
};
