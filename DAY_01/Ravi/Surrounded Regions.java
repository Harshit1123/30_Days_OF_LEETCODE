class Solution {
    public void solve(char[][] board) {
         
         if (board.length < 3 || board[0].length < 3) return;
        int ROW = board.length,COL = board[0].length;
        for (int i = 0; i < COL; i++) {
            if(board[0][i] == 'O') process(board,1,i);
            if(board[ROW-1][i] == 'O') process(board,ROW-2,i);
        }
        for (int i = 1; i < ROW-1; i++) {
            if(board[i][0] == 'O') process(board,i,1);
            if(board[i][COL-1] == 'O') process(board,i,COL-2);
        }
        for(int i = 1;i < ROW-1;i++){
            for (int j = 1; j < COL-1; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
    
    public   void process(char[][] board,int r,int c){
     if( r < 1 || r >  board.length-2 || c < 1 || c >  board[0].length-2||  board[r][c] != 'O'){
            return;
        }
        board[r][c] = '*';
        process(board,r+1,c);
        process(board,r-1,c);
        process(board,r,c+1);
        process(board,r,c-1);
    }
}
