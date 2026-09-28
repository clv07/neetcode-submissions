class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0], sell = 0, cooldown = 0;

        for (int i = 1; i < n; i++) {
            int p = prices[i];
            int prevBuy = buy, prevSell = sell;
            buy = max(buy, cooldown - p); // either buy or cooldown
            sell = prevBuy + p;     // profit made by selling today
            cooldown = max(cooldown, prevSell); // not taking any action or cooldown from previous day selling
        }

        return max(sell, cooldown);
        
    }
};
