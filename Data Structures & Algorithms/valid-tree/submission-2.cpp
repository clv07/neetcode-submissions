class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false; 

        // check for connection
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            // push in both direction
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        if (!dfs(0, -1, adj, visited)) 
            return false;

        for (bool v : visited)            
            if (!v) return false;
        return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int nei: adj[node]) {
            if (nei == parent) continue; // edge arrived on
            if (visited[nei]) return false;
            if (!dfs(nei, node, adj, visited)) return false;
        }
        return true;
    }
};
