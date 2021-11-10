class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit=0;
        
        for(int i=1; i<prices.size(); ++i) 
            Profit += max(prices[i] - prices[i-1], 0);
   
        return Profit;
    }
};
