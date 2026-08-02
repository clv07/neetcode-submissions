class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> curr, int target, int total, int i) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target) return;
            curr.push_back(nums[j]);
            dfs(nums, curr, target, total + nums[j], j);
            curr.pop_back();
        }
    }
};
