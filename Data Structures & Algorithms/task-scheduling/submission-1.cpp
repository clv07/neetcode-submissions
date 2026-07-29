class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t: tasks)
            freq[t - 'A']++;
        
        priority_queue<int> pq;
        for (int f: freq) {
            if (f > 0)
                pq.push(f);
        }

        queue<pair<int, int>> cool;
        int time = 0;

        while(!pq.empty() || !cool.empty()) {
            time++;
            if (!pq.empty()) {
                int cnt = pq.top() - 1;
                pq.pop();
                if (cnt > 0) 
                    cool.push({cnt, time + n});
            }
            if (!cool.empty()) {
                if (cool.front().second == time) {
                    int cnt = cool.front().first;
                    pq.push(cnt);
                    cool.pop();
                }
            }
        }

        return time;
    }
};
