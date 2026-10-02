class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hashmap; // key -> list of (timestamp, value)

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vec = hashmap[key];
        
        int l = 0, r = vec.size()-1;
        string res = "";

        while (l <= r) {
            int m = l + (r-l)/2;
            if (vec[m].first <= timestamp) {
                res = vec[m].second;
                l = m + 1;
            }
            else r = m - 1;
        }

        return res;
    }
};
