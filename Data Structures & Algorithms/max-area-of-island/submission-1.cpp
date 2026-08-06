class Solution {
public:
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) 
                    maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >=n) return 0;
        if (!grid[r][c]) return 0;

        grid[r][c] = 0;
        return 1 + dfs(grid, r+1, c) + dfs(grid, r-1, c) +
                 dfs(grid, r, c+1) + dfs(grid, r, c-1);

    }
};
