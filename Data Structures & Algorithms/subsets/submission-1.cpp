class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // initialize with empty vector
        vector<vector<int>> res = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }

        return res;
    }
};
