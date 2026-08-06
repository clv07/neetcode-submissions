class Solution {
public:
    int m, n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for (int r=0; r < m; r++) {
            for (int c=0; c < n; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (grid[r][c] != '1') return;

        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
};
