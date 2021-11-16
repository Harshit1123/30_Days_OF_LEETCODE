class Solution {
public:
    int pos(int mi,int m,int n){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=min(m,mi/i);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n;
        while(l<r){
            int mid=l+(r-l)/2;
            int ele=pos(mid,m,n);
            if(ele>=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return r;
    }
}
