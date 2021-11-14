class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int n=nums.size();
        int star_value=1,temp=1;
        int f=0;
        while(temp<10000)
        {    
            star_value=temp;
            for(int i=0;i<n;i++)
            { //  cout<<nums[i]<<"  "<<star_value<<endl;
                if(star_value+nums[i]>=1)
                { f=0;
                 //cout<<star_value<<"  "<<nums[i]<<endl;;
                 star_value=star_value+nums[i];
                }
                else 
                {   f=1;
                    temp++;
                    break;
                }
                
            }
            
            if(f==0)
                break;
            
           // temp++;
        }
        return temp;
    }
};
