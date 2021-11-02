// UniquePathsIII solution(Day 2)

class Solution {
public:
    int X[4] = {-1, 0, 1, 0};
    int Y[4] = {0, -1, 0, 1};
    
    void dfs(vector<vector<int> > &matrix, int i, int j, int count, int &ans)
    {
        int n = matrix.size(), m = matrix[0].size();
        
        if (i < 0 or j < 0 or i >= n or j >= m or matrix[i][j] == -1)
            return;
        
  
        if (matrix[i][j] == 2) 
		{
            if (count == -1) 
			{
                ans++;
            }
            return;
        }
        
        matrix[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            dfs(matrix, i + X[k], j + Y[k], count - 1, ans);
        }
        matrix[i][j] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& matrix) 			        // approach -- > DFS + backtracking

	{
        
        int i, j, x, y, count = 0, n = matrix.size(), m = matrix[0].size(), ans = 0;
        
        for (i = 0; i < n; i++) 				        // findign the start and count the number of positions we need to visit

		{
            for (j = 0; j < m; j++) 
			{
                if (matrix[i][j] == 1) 
				{
                    x = i, y = j;
                }
                
                if (matrix[i][j] == 0) 
				{
                    count++;
                }
            }
        }
        
        dfs(matrix, x, y, count, ans);
        return ans;
    }
};
