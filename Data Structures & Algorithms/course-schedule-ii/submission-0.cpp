class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto& p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int nei: adj[curr]) {
                indeg[nei]--;
                if (indeg[nei] == 0) q.push(nei);
            }
        } 

        if (res.size() != numCourses) return {};
        return res;
    }
};
