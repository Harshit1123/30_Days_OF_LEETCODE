class Solution {
public:
    int largestareaofhist(vector<int>& heights,int m)
    { int res=0;
        vector<int> left(m,0),right(m,0);
        for(int i=1;i<m;i++)
        { int j=i-1;
          while(j>=0 && heights[i]<=heights[j])
              j-=(left[j]+1);
           left[i]=i-(j+1); 
            
        }
        for(int i=m-2;i>=0;i--)
        { int j=i+1;
          while(j<m && heights[i]<=heights[j])
              j+=(right[j]+1);
           right[i]=j-(i+1); 
            
        }
        for(int i=0;i<m;i++)
        { res=max(res,heights[i]*(left[i]+1+right[i]));
            
        }
  
       return res;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       if(matrix.size()==0)
           return 0;
        int res=0;
        int n=matrix.size();int m=matrix[0].size();
        vector<int> heights(m,0);
        for(int i=0;i<n;i++)
         {  for(int j=0;j<m;j++)
              {  if(matrix[i][j]=='1')
                   heights[j]++;
                 else heights[j]=0;
             
              }
        
           res=max(res,largestareaofhist(heights,m));
            
         }
        return res;
      
    }
};
