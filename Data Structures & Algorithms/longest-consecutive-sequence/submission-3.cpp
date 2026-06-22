class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int len = 1;
        int maxlen = 1;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] - nums[i-1] == 1) {
                len += 1;
                if (len > maxlen) maxlen = len;
                continue;
            }
            len = 1;
        }

        return maxlen;
    }
};
