// approch we just check the consecutive days if the the prices is more the next day we just add it in our profit
// that means the buy the stock the perivois day(n) and sell it next day(n+1) 
// time complexity-O(n) space - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(i!=n-1 && prices[i]<prices[i+1])
            {profit=profit+prices[i+1]-prices[i];
             //cout<<i<<"\t"<<prices[i]<<endl; 
             //cout<<i;
            }
        }
        return profit;
        
    }
};
