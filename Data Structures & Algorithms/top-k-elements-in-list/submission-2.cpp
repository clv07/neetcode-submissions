class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count frequency of each number
        unordered_map<int, int> freq;
        for (int n: nums) {
            freq[n]++;
        }

        // modify index as frequency (frequency is at most nums length)
        vector<vector<int>> cnt(nums.size() + 1);
        for (auto &[key, value]: freq) {
            cnt[value].push_back(key);
        }

        // return result
        vector<int> result;
        for (int i = cnt.size()-1; i >= 0 && result.size() < k; i--) {
            for (int c: cnt[i])
                result.push_back(c);
            if (result.size() == k) break;
        }

        return result;
    }
};
