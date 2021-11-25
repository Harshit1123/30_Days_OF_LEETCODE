class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxsum=INT_MIN;
        int maxend_here=0;
        
        for(int i=0;i<nums.size();i++)
        {
            maxend_here+=nums[i];
            maxsum=max(maxsum,maxend_here);
            
            if(maxend_here<0)
              maxend_here=0;
        }
        return maxsum;
        
    }
};
