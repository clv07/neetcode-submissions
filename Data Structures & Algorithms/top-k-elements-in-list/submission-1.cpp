class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int n: nums) 
            cnt[n]++; 
        
        vector<vector<int>> buckets (nums.size()+1);
        for (auto &[key, val]: cnt) 
            buckets[val].push_back(key);
        
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0  && result.size() < k; i--) {
            for (int b: buckets[i]) {
                result.push_back(b);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
