class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        }; 

        visited[0][0] = true;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            if (row == m - 1 && col == n - 1) return cost;   // first pop = minimum
            for (auto &dir: dirs) {
                int nr = row + dir[0], nc = col + dir[1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                pq.push({max(cost, grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }
};
