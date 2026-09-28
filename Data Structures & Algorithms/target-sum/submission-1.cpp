class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P = the sum of numbers marked +
        // N = the sum of numbers marked -
        // feasibility: P must be a non-negative whole number
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0; // unreachable
        if ((sum + target) % 2) return 0; // P not an integer

        int P = (sum + target) / 2; // capacity
        vector<int> dp(P+1, 0);
        dp[0] = 1; // empty subset: one way

        for (int n: nums)
            for (int a = P; a >= n; a--) // descending: each item once
                dp[a] += dp[a - n];

        return dp[P];

    }
};
