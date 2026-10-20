class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket: tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dest]: adj) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> res;
        stack<string> stk;
        stk.push("JFK");

        while (!stk.empty()) {
            string curr = stk.top();
            if (adj[curr].empty()) {
                res.push_back(curr);
                stk.pop();
            }
            else {
                string next = adj[curr].back();
                adj[curr].pop_back();
                stk.push(next);
            }
        }

        reverse(res.rbegin(), res.rend());
        return res;
    }
};
