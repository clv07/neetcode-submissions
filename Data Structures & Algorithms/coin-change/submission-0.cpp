class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // initialize a dp array with first element as 0 and the rest as large amount
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }

        return dp[amount] > amount? -1 : dp[amount];

    }
};
