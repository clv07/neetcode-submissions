class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    int dirs[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0));
        int maxLen = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                maxLen = max(maxLen, dfs(matrix, i, j));
        return maxLen;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j]) return memo[i][j];
        int best = 1;
        for (auto& d: dirs) {
            int r = i + d[0], c = j + d[1];
            if (r >= 0 && r < m && c >= 0 && c < n && matrix[i][j] < matrix[r][c])
                best = max(best, 1 + dfs(matrix, r, c));
        }
        return memo[i][j] = best;
    }
};
