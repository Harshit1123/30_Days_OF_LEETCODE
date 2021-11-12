class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0, sum = 0;
        
        for (auto num : nums) {
            sum += num;
            res = min(res, sum);
        }
        
        return -res + 1;
    }
};
