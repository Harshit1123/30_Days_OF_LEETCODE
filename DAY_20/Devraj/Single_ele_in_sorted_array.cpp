class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int s=0,e=nums.size()-1;
        while(s<e)
           { int mid= s+(e-s)/2;
          
             if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
              s=mid+1;
             else
              e=mid;
           }
        return nums[s];
        
    }
};
