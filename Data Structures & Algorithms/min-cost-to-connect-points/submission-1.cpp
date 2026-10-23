class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int m = points.size();
        vector<int> dist(m, INT_MAX); // dist[v] = cheapest edge connecting point v to the tree so far
        vector<bool> inTree(m, false); // inTree[v] = whether point v has already been added to the tree

        dist[0] = 0; // base case: start the tree from point 0 (costs nothing)
        int total = 0;

        // each round adds exactly one point, and m round connects everthing
        for (int round = 0; round < m; round++) {
            // 1. Pick the outside point that's cheapest to attach
            //    (u == -1 means no candidate picked yet this round)
            int u = -1;
            for (int i = 0; i < m; i++)
                if (!inTree[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;

            // 2. add it to the tree and pay its cost
            inTree[u] = true;
            total += dist[u];

            // 3. u is now in the tree, so outside node might attach more cheaply through u: update their cost
            for (int i = 0; i < m; i++)
                if (!inTree[i])
                    dist[i] = min(dist[i], abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]));
        }

        return total;
    }
};
