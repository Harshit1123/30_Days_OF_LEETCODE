class Solution {
public:
    int bsearch(int n) {
        int lo(1), hi(n), ans(1);
        
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            long long t = mid * 1LL * (mid * 1LL + 1) / 2;
            if (t <= n * (1ll)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
    
    int arrangeCoins(int n) {
        return bsearch(n);   
    }
};
