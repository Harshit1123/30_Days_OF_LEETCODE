class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n=temperatures.length;
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && temperatures[i]>=temperatures[st.peek()])
                st.pop();
            ans[i]=st.isEmpty()?0:st.peek()-i;
            st.push(i);
        }
        return ans;
    }
}
