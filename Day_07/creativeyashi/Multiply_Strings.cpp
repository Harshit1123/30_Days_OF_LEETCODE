class Solution {
public:
    
    
    string multiply(string num1, string num2) {
        
        if(num1 =="0" || num2 =="0")
            return "0";
        
        int str[num1.size() + num2.size()] ;
        for(int i=0;i<num1.size()+num2.size();i++)
            str[i] = 0;
        
        for(int i=num1.size()-1,ptr1 =0 ;i>=0;i--,ptr1 ++){
            for(int j=num2.size()-1,ptr2 =0;j>=0;j--,ptr2++){
                int t_m = (num1[i]-'0') * (num2[j] -'0');
                str[ptr1+ptr2] += t_m;
                if(str[ptr1+ptr2]/10 >0){
                    str[ptr1+ptr2+1] += str[ptr1+ptr2]/10;
                    str[ptr1+ptr2] %=10;
                }
            }
        }
        
        int size = num1.size()+num2.size();
        
        string ans;
        for(int i=size-1;i>=0;i--){
            if(i==size-1 && str[i] ==0)
                continue;
            ans += str[i]+'0';
            
        }
        
        return ans;
    }
};
