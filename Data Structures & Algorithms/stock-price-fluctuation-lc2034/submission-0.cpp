class StockPrice {
private:
    map<int, int> record;       // for ordered and unique (timestamp, record)
    multimap<int, int> priceMap;  // for ordered (record, timestamp)

public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        // insert/update record
        auto it = record.find(timestamp);
        if (it != record.end()) { // record exist
            int oldPrice = it->second;
            auto range = priceMap.equal_range(oldPrice);
            for (auto p = range.first; p != range.second; p++) {
                // remove (oldPrice, timestamp) from priceMap
                if (p->second == timestamp) { 
                    priceMap.erase(p);
                    break;
                }
            }
        }

        record[timestamp] = price; // insert / overwrite record
        priceMap.insert({price, timestamp}); // insert (newPrice, timestamp) into priceMap
    }
    
    int current() {
        return record.rbegin()->second;
    }
    
    int maximum() {
        return priceMap.rbegin()->first;
    }
    
    int minimum() {
        return priceMap.begin()->first;
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