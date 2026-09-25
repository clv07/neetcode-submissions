class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = 0, prev2 = 0;
        for (int i = 2; i <= n; i++) {
            int curr = min(prev1 + cost[i-1], // one step from i-1
                           prev2 + cost[i-2]); // two step from i-2
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
};
