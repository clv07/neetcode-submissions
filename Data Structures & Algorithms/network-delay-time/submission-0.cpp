class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n); // adj[ui] = {(vi, ti)}
        for (auto &t: times) 
            adj[t[0]-1].push_back({t[1]-1, t[2]});
        
        vector<int> dist(n, INT_MAX);
        int visited = 0, result = 0;
        
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> minHeap; // (time, node)
        minHeap.push({0, k-1});

        while(!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();
            if (dist[node] != INT_MAX) continue;
            dist[node] = time;
            visited++;
            result = time;
            for (auto [v, t]: adj[node]) {
                if (dist[v] == INT_MAX) minHeap.push({time + t, v});
            }
        }

        return visited == n? result : -1;

    }
};
