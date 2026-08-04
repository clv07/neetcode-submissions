class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // backtracking with masking
        dfs(nums, {}, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> perm, int mask) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!(mask & (1<<i))) {
                perm.push_back(nums[i]);
                dfs(nums, perm, mask | (1<<i));
                perm.pop_back();
            }
        }
    }
};
