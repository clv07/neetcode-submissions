class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we are discarding larger element, so use maxHeap

        priority_queue<pair<int, vector<int>>> pq;
        for(auto& p: points) {
            int d = p[0]*p[0] + p[1]*p[1]; // monotonic
            pq.push({d, p});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
