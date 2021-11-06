class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xorr=0;
        int n=nums.size();
        for(auto x:nums)
            xorr^=x;
        int set_bit = xorr & ~(xorr-1);   //This calculates rightmost set bit
        int first=0,second=0;
         for(int i=0;i<n;i++)
            {  if(set_bit&nums[i])
                  first^=nums[i];
               else
                 second^=nums[i];
            }
         return {first,second};
        
    }
};
