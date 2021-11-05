// Arranging Coins- DAY-05 Solution

class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int diff=n;
        int i=0;
        while(diff>0)
        { count++;
          i++;
          diff -= i;
        }
        if(diff==0)
           { return count;
           }
        return count-1;

    }
};
