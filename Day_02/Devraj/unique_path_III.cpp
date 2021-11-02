class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& grid,int x,int y,int &count,int viscount,int empty)
    {     if(grid[x][y]==2 )
             {  if(empty==viscount-1)
                   count++;
                return;
             }
          viscount++;
          grid[x][y]=-1;
          for(int i=0;i<4;i++)
             { int newx=x+dx[i];
               int newy=y+dy[i];
               if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size()&&(grid[newx][newy]==0 || grid[newx][newy]==2 ))
                    dfs(grid,newx,newy,count,viscount,empty);
             }
       grid[x][y]=0;
   }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        int viscount=0,empty=0;
        int startx,starty;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                { startx=i;
                   starty=j;
                }
                if(grid[i][j]==0)
                    empty++;
            }
        }
        dfs(grid,startx,starty,count,viscount,empty);
        return count;
    }
};
