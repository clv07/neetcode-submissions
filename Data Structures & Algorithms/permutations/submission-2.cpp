class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

    void dfs(vector<int>& nums, int k, vector<vector<int>> & res) {
        if (k == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (size_t i = k; i < nums.size(); i++) {
            swap(nums[k], nums[i]);
            dfs(nums, k + 1, res);
            swap(nums[k], nums[i]);
        }
    }
};
