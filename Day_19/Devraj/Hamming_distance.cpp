class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while(x >0 || y>0)
        {
            if(x>=0 && y>=0)
            {
                count+= (x^y)%2;
                x=x>>1;
                y=y>>1;
                
            }
            else if(x>=0)
            {  count+= x%2;
               x=x>>1;
            }
            else
            {  count+= y%2;
                y=y>>1;
            }
            
        }
        return count;
        
    }
};
