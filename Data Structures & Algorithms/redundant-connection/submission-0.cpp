class Solution {
public:
    vector<int> parent, rank;

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]); // path compression
        return parent[node];
    }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;  // already connected, cycle detected
        if (rank[ra] < rank[rb]) swap(ra, rb); // union by rank
        parent[rb] = ra;
        if (rank[ra] == rank[rb]) rank[ra]++;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.assign(n+1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto& e: edges)
            if (!unite(e[0], e[1])) return e;
        
        return {};
    }
};
