class Solution {
public:
    int arrangeCoins(int n) {
        int i=1,count=0,sum=0,rowsum=0;
        while(n>=0){
        
            
            sum=sum+i;
            rowsum=rowsum+1;
            if(rowsum<=n){count++;}
            n=n-sum; 
        }  
    return count;
    } 
};
