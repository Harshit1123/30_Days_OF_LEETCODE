class Solution {
public:
    int arrangeCoins(int n) {
        int s=0,i=1;
        
        while(n>=i){
           n-=i;
            i++;
            s++;
        };
        return s;
    }
};
