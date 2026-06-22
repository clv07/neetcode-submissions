class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0, l=0, r=1;

        // if left pointer is larger than right, move both forward
        // else only move right pointer forward

        while (l < r && r < prices.size()) {
            if (prices[l] > prices[r]) {
                l = r;
                r = l + 1;
                continue;
            }
            else {
                maxp = max(prices[r] - prices[l], maxp);
                r++;
            }
        }

        return maxp;
    }
};
