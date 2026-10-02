class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> table;
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // binary search to find the valid boundary
        auto& pairs = table[key];
        string valid = "";
        int l = 0, r = pairs.size()-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (pairs[m].first <= timestamp) {
                valid = pairs[m].second;
                l = m + 1; // everything to the left is valid and earlier, so search for right
            }
            else r = m - 1; // everything to the right is too late
        }

        return valid;

    }
};
