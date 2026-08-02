class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, {}, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<int> curr, int target, int total, int i) {
        if (total == target) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j-1]) continue; // not using same sibling value 
            if (total + candidates[j] > target) break; // sorted, so summing the rest will exceed the target
            curr.push_back(candidates[j]);
            dfs(candidates, curr, target, total + candidates[j], j+1);
            curr.pop_back();
        }
    }
};
