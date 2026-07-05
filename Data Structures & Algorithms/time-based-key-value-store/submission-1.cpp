class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hashmap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& pairs = hashmap[key];

        int l = 0, r = pairs.size() - 1;
        string res = "";    // return default "" if none valid

        while (l <= r) {
            int m = l + (r-l)/2;

            if (pairs[m].first <= timestamp) {
                res = pairs[m].second; // valid candidate so far
                l = m + 1;              // continue to find later one
            }
            else r = m - 1; // too late, go early
        }

        return res;

    }
};
