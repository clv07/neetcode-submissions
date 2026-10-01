class StockPrice {
private:
    unordered_map<int, int> record;  // for unique (timestamp, record)
    multiset<int> prices;  // duplicate price for max and min
    int latest = 0; // for tracking latest timestamp
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        // insert/update record
        auto it = record.find(timestamp);
        if (it != record.end()) { // record exist
            prices.erase(prices.find(it->second)); // remove one copy of old price
        }

        record[timestamp] = price; // insert/overwrite record
        latest = max(latest, timestamp); // update latest timestamp
        prices.insert(price); // insert new price into priceMap
    }
    
    int current() {
        return record[latest];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
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