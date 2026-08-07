class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> alt(m, vector<bool>(n, false));

        for (int c = 0; c < n; c++) {
            dfs(heights, 0, c, pac, heights[0][c]); // top (pacific)
            dfs(heights, m-1, c, alt, heights[m-1][c]); // bottom (atlantic)
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, r, 0, pac, heights[r][0]); // left (pacific)
            dfs(heights, r, n-1, alt, heights[r][n-1]); //right (atlantic)
        }

        vector<vector<int>> res;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac[r][c] && alt[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& h, int r, int c, vector<vector<bool>>& seen, int prev) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (seen[r][c]) return;
        if (h[r][c] < prev) return; // cannot flow uphill into previous

        seen[r][c] = true;
        dfs(h, r+1, c, seen, h[r][c]);
        dfs(h, r-1, c, seen, h[r][c]);
        dfs(h, r, c+1, seen, h[r][c]);
        dfs(h, r, c-1, seen, h[r][c]);
    }
};
