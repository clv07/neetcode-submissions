class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        }; 

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            if (row == m - 1 && col == n - 1) return cost;   // first pop = minimum
            if (visited[row][col]) continue;                 // stale duplicate
            visited[row][col] = true;
            for (auto &dir: dirs) {
                int nr = row + dir[0], nc = col + dir[1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) continue;
                pq.push({max(cost, grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }
};
