/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });

        vector<int> ends = {intervals[0].end};
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            bool update = false;
            for (int j=0; j< ends.size() ; j++) {
                if (intervals[i].start >= ends[j]) {
                    ends[j] = intervals[i].end;
                    update = true;
                    break;
                }
            }
            if (!update) ends.push_back(intervals[i].end);
        }

        return ends.size();
    }
};
