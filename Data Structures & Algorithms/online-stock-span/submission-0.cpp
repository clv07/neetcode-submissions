class StockSpanner {
private:
    vector<int> res;
    int totalLen = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        res.push_back(price);
        totalLen++;
        int count = 0; 
       for (int i = totalLen-1; i >= 0; i--)  {
            if (res[i] <= price) count++;
            else break;
       }
       return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */