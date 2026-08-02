class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {    
        vector<int> curr;
        dfs(nums, target, curr, 0);
        return res;
    }

    void dfs(vector<int>& nums, int target, vector<int>& curr, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, target - nums[i], curr, i);

        curr.pop_back();
        dfs(nums, target, curr, i + 1);
    }
};
