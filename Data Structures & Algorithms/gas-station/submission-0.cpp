class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0; // check feasibility
        int tank = 0; // running fuel since the current candidate start
        int start = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            if (tank < 0) {     // candidate start failed at i
                start = i + 1;    // skip the whole window [start, i]
                tank = 0;
            }
        } 

        return total >= 0? start : -1;

    }
};
