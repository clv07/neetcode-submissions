class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sort interval by start value
        sort(intervals.begin(), intervals.end());
        int m = intervals.size(), n = queries.size();

        // record original position of queries
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0); //fill sequencing increasing values starting at 0
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });

        // initialize result
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> res(n, -1);
        
        // goal of min heap: retain intervals where left <= query <= right
        int i = 0;
        for (int k: idx) {
            int q = queries[k];
            while(i < m && q >= intervals[i][0]) { // insert (interval size, right) if left <= query
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && q > pq.top().second) // evict if query > right
                pq.pop();
            if (!pq.empty())
                res[k] = pq.top().first; // smallest interval size for this query
        }

        return res;

    }
};
