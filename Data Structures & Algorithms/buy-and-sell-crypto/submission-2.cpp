class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum = prices[0], maxPrice = 0;
       for(int price:prices){
            maxPrice = max(maxPrice, price-minNum);
            minNum = min(minNum, price);
       }
       return maxPrice;
    }
};
