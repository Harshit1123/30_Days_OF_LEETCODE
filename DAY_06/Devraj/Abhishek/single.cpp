// used map and stored the frequency of elements 
// complexity- O(n)  both space and time 

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        
        for(int i=0;i<nums.size();i++)
            if(m[nums[i]]==1)
                ans.push_back(nums[i]);
        
        return ans;
                
        
    }
};
