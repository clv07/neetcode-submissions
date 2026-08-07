class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        
        // push rotten to queue and count fresh
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }

        // if there is no fresh oranges
        if (fresh == 0) return 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int time = 0;

        // mark fresh to rotten if encounter one
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto[r, c] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int rj = r + dr[j];
                    int cj = c + dc[j];
                    if (rj < 0 || rj >= m || cj < 0 || cj >= n) continue;
                    if (grid[rj][cj] != 1) continue;
                    grid[rj][cj] = 2;
                    fresh--;
                    q.push({rj, cj});
                }
            }
            time++;
        }

        return fresh == 0? time : -1;

    }
};
