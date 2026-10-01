class StockPrice {
private:
    unordered_map<int, int> record;  // for unique (timestamp, record)
    int latest = 0; // for tracking latest timestamp
    
    // (price, timestamp)
    priority_queue<pair<int, int>> maxHeap; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        record[timestamp] = price; // insert/overwrite record
        latest = max(latest, timestamp); // update latest timestamp
        maxHeap.push({price, timestamp}); // insert for maximum price heap
        minHeap.push({price, timestamp}); // insert for minimum price heap
    }
    
    int current() {
        return record[latest];
    }
    
    int maximum() {
        // remove stale entry from maximum price heap
        while(record[maxHeap.top().second] != maxHeap.top().first)
            maxHeap.pop();
        return maxHeap.top().first;
    }
    
    int minimum() {
        // remove stale entry from minimum price heap
        while(record[minHeap.top().second] != minHeap.top().first)
            minHeap.pop();
        return minHeap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */