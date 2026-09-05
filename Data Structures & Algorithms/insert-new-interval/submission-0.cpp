class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // end < newStart
        while (i < n && intervals[i][1] < newInterval[0]) 
            res.push_back(intervals[i++]);
        
        // merge overlapping where start <= running end
        int s = newInterval[0], e = newInterval[1];
        while (i < n && intervals[i][0] <= e) {
            s = min(s, intervals[i][0]); // min of start 
            e = max(e, intervals[i][1]); // max of end
            i++;
        }
        res.push_back({s, e});

        // push the remaining intervals
        while(i < n)
            res.push_back(intervals[i++]);
        return res;

    }
};
