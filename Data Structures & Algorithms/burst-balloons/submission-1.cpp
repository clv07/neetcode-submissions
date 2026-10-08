class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n+2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i+1] = nums[i]; // pad 1 at each side of the array so boundary balloons have neighbors
        }

        vector<vector<int>> dp(n+2, vector<int>(n+2,-1));
        return dfs(newNums, 1, newNums.size()-2, dp);
    }

    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l > r) return 0;    // empty interval -> 0 coins
        if (dp[l][r] != -1) return dp[l][r]; 

        dp[l][r] = 0;
        for (int i = l; i <=r; i++) {
            int coins = nums[l-1] * nums[i] * nums[r+1]; // last burst at i
            coins += dfs(nums, l, i-1, dp) + dfs(nums, i+1, r, dp); // left [l...i-1] and right [i+1...r] are independent, so i stays alive as a wall between them
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r]; //  max coins from bursting all balloons in [l][r]
    }
};
