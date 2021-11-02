// approach-> so we chcek all the borders abd if there is any 'O' on the borders we call the dfs function 
// this func checks all the surronding elemnts (that they are 'O' or not) and if there are we marked them as 'F'
//  and at last we flip all the remaning O into X and all elemnets marked into 'F' back to 'O'

class Solution {
public:
    void dfs(vector<vector<char>> &board,int row,int col)
    {
	//to check if the current position is inside the board and is an 'O'
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 'O') 
            return;
		
        board[row][col] = 'F';
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
		if(n<=2 && m<=2)
          ;  
		//checking on left and right
      else
      {    for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O') 
                dfs(board,i,0);
            if(board[i][m-1] == 'O') 
                dfs(board,i,m-1);
        }
        
		//checking on up and down
        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O') 
                dfs(board,0,j);
            if(board[n-1][j] == 'O') 
                dfs(board,n-1,j);
        }
        
		
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'F')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O') 
                    board[i][j] = 'X';
            }
        }
      } 
        
    }
};
