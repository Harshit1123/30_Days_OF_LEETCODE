class Solution {
public:
    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    void dfs(vector<vector<char>>& board,int x,int y,int n,int m)
    {    if(x<0 || y<0 || x>= n || y>=m || board[x][y]=='X' || board[x][y]=='V')
           return;
        
        board[x][y]='V';
        for(int i=0;i<4;i++)
        {   int newx=x+X[i];
            int newy=y+Y[i];
            dfs(board,newx,newy,n,m);
           
        }
        
    }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();int m=board[0].size();
        for(int i=0;i<n;i++)
        {   if(board[i][0]=='O')           //DFS for both left and right boundary
              dfs(board,i,0,n,m);
            if(board[i][m-1]=='O')
              dfs(board,i,m-1,n,m);
                 
        }
         for(int i=0;i<m;i++)
        {   if(board[0][i]=='O')
              dfs(board,0,i,n,m);                         //DFS for both upper and lower boundary
            if(board[n-1][i]=='O')
              dfs(board,n-1,i,n,m);
            
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<"\n";
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                  if(board[i][j]=='V')                  // If visited in DfS,Then convert it to O again
                      board[i][j]='O';
                  else if(board[i][j]=='O')
                        board[i][j]='X';                   // If 0 Then convert it to X
                
                
                
            }
        }
        
       
    }
};
