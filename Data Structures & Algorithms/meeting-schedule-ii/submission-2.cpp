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
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });

        priority_queue<int, vector<int>, greater<int>>pq; // end times, smallest on top
        for (const auto& in: intervals) {
            if (!pq.empty() && pq.top() <= in.start) pq.pop(); // earliest room is free, reuse the room
            pq.push(in.end);
        }
        
        return pq.size();
    }
};
