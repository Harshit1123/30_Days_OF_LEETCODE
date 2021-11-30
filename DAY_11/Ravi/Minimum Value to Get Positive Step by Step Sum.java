// Simple java iteration code.

class Solution {
        public int minStartValue(int[] nums) {
        int valReq = 1;

        for(int i=nums.length-1;i>=0;i--) {
            if(nums[i]<=0) {
                valReq = valReq-nums[i];
            } else  {
                valReq = Math.max(1,valReq-nums[i]);
            }
        }

        return valReq;
    }
        
    }
