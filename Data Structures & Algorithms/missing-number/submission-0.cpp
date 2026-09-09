class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n; i++) ans ^= i;
        for (int& num: nums) ans ^= num;
        return ans;
    }
};
