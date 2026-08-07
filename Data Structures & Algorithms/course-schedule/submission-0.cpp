class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // adjacency list for unlocked class indexed by source
        vector<int> indeg(numCourses, 0); // in degree for counting number of prereq left indexed by target

        // loop through every prerequisites to fill in adj and indeg
        for (auto& p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        // push the now takeable class 
        queue<int> q;
        for (int i=0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int taken = 0;
        while(!q.empty()) {
            // get current class
            int curr = q.front();
            q.pop();
            taken++;
            for (int nei: adj[curr]) {
                indeg[nei]--; // decrement prereq count for satisfying prereq curr
                if (indeg[nei] == 0) 
                    q.push(nei);
            }
        }

        return taken == numCourses;

    }
};
