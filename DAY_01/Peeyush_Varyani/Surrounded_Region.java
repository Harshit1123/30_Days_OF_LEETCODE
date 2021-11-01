public class Solution {
    public void solve(char[][] board) {
        int rows = board.length;
        if(rows == 0) return;
        int cols = board[0].length;
        
        for(int i = 0; i < cols; i++) {
            // check first row's O
            if(board[0][i] == 'O') {
                // change it to other symbol
                board[0][i] = '#';
                dfs(board, 0, i);
            }
            // check the last row
            if(board[rows - 1][i] == 'O') {
                board[rows - 1][i] = '#';
                dfs(board, rows - 1, i);
            }

        }
        
        for(int i = 0; i < rows; i++) {
            // check first col
            if(board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, i, 0);
            }
            // check last col
            if(board[i][cols - 1] == 'O') {
                board[i][cols - 1] = '#';
                dfs(board, i, cols - 1);
            }
        }
        
        // change O to X
        changeTo(board, 'O', 'X');
        
        // change # to O
        changeTo(board, '#', 'O');
        return;
    }
    
    public void dfs(char[][] board, int row, int col) {
        // check up
        if(row > 0) {
            if(board[row - 1][col] == 'O') {
                board[row - 1][col] = '#';
                dfs(board, row - 1, col);
            }
        }
        // check left
        if(col > 0) {
            if(board[row][col - 1] == 'O') {
                board[row][col - 1] = '#';
                dfs(board, row, col - 1);
            }
        }
        // check right
        if(row < board.length - 1) {
            if(board[row + 1][col] == 'O') {
                board[row+1][col] = '#';
                dfs(board, row+1, col);
            }
        }
        // check down
        if(col < board[0].length - 1) {
            if(board[row][col+1] == 'O'){
                board[row][col+1] = '#';
                dfs(board, row, col+1);
            }
        }
        return;
    }
    
    public void changeTo(char[][] board, char from, char to) {
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(board[i][j] == from) {
                    board[i][j] = to;
                }
            }
        }
        return;
    }
}
