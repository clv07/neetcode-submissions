class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int& s: stones)
            pq.push(s);

        int res = 0;
        
        while(pq.size() > 1) {
            // pop first two stones
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) pq.push(abs(y-x));
        }

        if (pq.size() == 1) res = pq.top();

        return res;
    }
};
