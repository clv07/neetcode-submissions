class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0], res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            int tmp = curMax;
            curMax = max({n, tmp * n, curMin * n});
            curMin = min({n, tmp * n, curMin * n});
            res = max(res, curMax);
        }

        return res;
    }
};
