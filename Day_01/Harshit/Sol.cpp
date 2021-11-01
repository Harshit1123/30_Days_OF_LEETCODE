class Solution {
public:
         
        void solve(vector<vector<char>>& board) 
{
	const int n = size(board);
	const int m = empty(board) ? 0 : size(board.front());
    
	function<void(int, int)> dfs;
	dfs = [&](int i, int j)
	{
		board[i][j] = 'Y';
		for (const auto[x, y] : array<pair<int, int>, 4>{ pair{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1} })
			if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
				dfs(x, y);
	};
    
    for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
             if ((i * j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O')
                 dfs(i, j);
	
	for (int i = 0; i < n; ++i) {
        replace(begin(board[i]), end(board[i]), 'O', 'X');
        replace(begin(board[i]), end(board[i]), 'Y', 'O');
    }
}
        
    
};
