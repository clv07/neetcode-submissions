class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>&b) {
                return a[1] < b[1];
            });
        int count = 0;
        int prevEnd = INT_MIN;
        for (const auto& in: intervals) {
            if (in[0] >= prevEnd) prevEnd = in[1]; //keep
            else count++;
        }
        return count;
    }
};
