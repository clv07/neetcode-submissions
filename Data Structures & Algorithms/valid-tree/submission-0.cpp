class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false; 

        // check for connection
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            // push in both direction
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int seen = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei: adj[node]) {
                if(visited[nei]) continue;
                visited[nei] = true;
                seen++;
                q.push(nei);
            }
        }

        return seen == n;

    }
};
