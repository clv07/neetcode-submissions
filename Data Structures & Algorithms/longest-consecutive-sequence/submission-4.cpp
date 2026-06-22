class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> res;

        for (int n: nums) {
            res.insert(n);
        }

        int len = 1;
        int maxlen = 1;
        for (auto i=res.begin(); i != res.end(); i++) {
            if (next(i) == res.end()) break;
            auto curr = *i;
            auto nextVal = *std::next(i);
            if (nextVal - curr > 1) {
                len = 1;
                continue;
            }
            len += 1;
            if (len > maxlen) maxlen = len;
        }

        return maxlen;
    }
};
