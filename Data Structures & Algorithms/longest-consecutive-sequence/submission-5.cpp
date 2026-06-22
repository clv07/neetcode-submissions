class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int n: numSet) {
            if (numSet.find(n-1) == numSet.end()) {
                int length = 1;
                while (numSet.find(n+length) != numSet.end()) length++;
                maxLen = max(length, maxLen);
            }
        }

        return maxLen;
    }
};
