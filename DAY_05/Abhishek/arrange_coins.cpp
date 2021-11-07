
class Solution {
public:
    int arrangeCoins(int n) {
        int i=1,c=0;
        while(true)
        {
            n=n-i;
            if(n>=0)
                c++;
            else
                break;
            i++;
        }
        return c;
        
    }
};
