class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }

    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[i]);
        dfs(nums, i+1, subset, res);
        
        // exclude
        subset.pop_back();
        dfs(nums, i+1, subset, res);
    }
};
