class Solution {
public:
    int rob(vector<int>& nums) {
        // split into two range: one exclude first house [1...n-1] and the other exclude last house [0...n-2]
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }

    int robHelper(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
