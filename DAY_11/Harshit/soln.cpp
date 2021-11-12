class Solution {
public:
    int minStartValue(vector<int>& nums) {
          int r = 0, s = 0;
        
         for (auto num : nums){
            s += num;
            r = min(r, s);
        }
        
        return -r + 1;
    }
        
    
};
 
