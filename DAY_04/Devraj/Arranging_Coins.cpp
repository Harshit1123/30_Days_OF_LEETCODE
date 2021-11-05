class Solution {
public:
    int arrangeCoins(int n) {
        int k=0;
        int rem=n;
        int i=0;
        while(rem>0)
        { k++;
          i++;
          rem-= i;
        }
        if(rem==0)
            return k;
        return k-1;
        
    }
};
