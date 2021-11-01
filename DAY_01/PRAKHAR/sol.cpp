// my solution = surrounded region
// link : https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int X[4] = { -1, 0, 0, 1};
    int Y[4] = {0, -1, 1, 0};

    void dfs(vector<vector<char>> &board, int i, int j)
    {

        int n = board.size(), m = board[0].size();
        // over size
        if (i < 0 or j < 0 or i >= n or j >= m)
            return;

        // water - skip
        if (board[i][j] != 'O')
            return;

        board[i][j] = '#';

        // found 'O'

        // cout << i << ' ' << j << endl;
        for (int k = 0; k < 4; k++) {
            dfs(board, i + X[k], j + Y[k]);
        }
        
        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

    }
};
