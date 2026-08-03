class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int start = 0, end = 0;

        for(int i=0; i < nums.size(); i++) {
            start = (i > 0 && nums[i] == nums[i-1])? end : 0;
            end = res.size();
            for (int j=start; j < end; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }          
        }

        return res;
        
    }
};
