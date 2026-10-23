class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return x == parent[x]? x : parent[x] = find(parent[x]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int m = points.size();
        vector<array<int, 3>> edges; // (cost, i, j)

        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
                edges.push_back({
                    abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), 
                    i, j
                });

        sort(edges.begin(), edges.end()); // edge with minimum cost appears first

        parent.resize(m);
        iota(parent.begin(), parent.end(), 0);
        int total = 0, used = 0;

        for (auto &[cost, i, j]: edges) {
            int ri = find(i), rj = find(j);
            if (ri == rj) continue; // within same group -> add this edge will create cycle
            parent[ri] = rj;
            total += cost;
            if (++used == m-1) break; // tree is completed
        }

        return total;
    }
};
