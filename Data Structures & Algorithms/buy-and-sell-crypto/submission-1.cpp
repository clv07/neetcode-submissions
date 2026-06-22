class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0, l=0, r=1;

        // left pointer for buy day, and right pointer for sell day
        // if left < right, compute profit and store its max
        // else update left = right

        while (r < prices.size()) {
            if (prices[l] < prices[r]) 
                maxp = max(prices[r] - prices[l], maxp);
            else 
                l = r;
            r++;
        }

        return maxp;
    }
};
