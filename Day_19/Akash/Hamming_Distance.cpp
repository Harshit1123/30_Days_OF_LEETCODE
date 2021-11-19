class Solution {
public:
    int hammingDistance(int x, int y) {
        string xs = tobin(x);
        string ys = tobin(y);
        int count =0;
        for(int i=0;i<32;i++){
            if(xs[i]!=ys[i])
                count++;
        }
        return count;
    }
    string tobin(int n){
        string ans ="";
        for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans+="1";
        else
            ans+= "0";
        }
        return ans;
    }
};