class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int best = nums[0];

        for (int i=1; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]); // extend current sum with nums[i] or start fresh at nums[i]
            best = max(best, cur);
        }

        return best;
    }
};
