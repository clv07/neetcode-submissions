class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            // for every unvisited connected component, increment count and
            // mark every other connected node as visited 
            if (!visited[i]) {
                count++; 
                dfs(i, visited, adj);
            }
        }
        return count;
    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        for (int nei: adj[node]) {
            if (!visited[nei])
                dfs(nei, visited, adj);
        }
    }
};
