class Solution {
public:
    int X[4] = {-1, 0, 1, 0};
    int Y[4] = {0, -1, 0, 1};
    
    void dfs(vector<vector<int> > &grid, int i, int j, int count, int &ans)
    {
        int n = grid.size(), m = grid[0].size();
        
        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == -1)
            return;
        
        // cout << i << ' ' << j << ' ' << count << endl;
        // cout << ans << endl;
        if (grid[i][j] == 2) {
            if (count == -1) {
                ans++;
            }
            return;
        }
        
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            dfs(grid, i + X[k], j + Y[k], count - 1, ans);
        }
        grid[i][j] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        // approach -- > DFS + backtracking
        
        int i, j, x, y, count = 0, n = grid.size(), m = grid[0].size(), ans = 0;
        
        // find start and count the number of positions we need to visit
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    x = i, y = j;
                }
                
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        
        dfs(grid, x, y, count, ans);
        return ans;
    }
};
