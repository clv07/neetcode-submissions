class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector <int>> res;
        for(int i=0; i<nums.size(); i++) {
            // skip anchor > 0 (no solution will be found)
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue; //skip duplicate

            int l = i+1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) r--;
                else if (sum < 0) l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    // advance index
                    l++;
                    r--;

                    // skip duplicates
                    while(l < r && nums[l] == nums[l-1]) l++; 
                    while(l < r && nums[r] == nums[r+1]) r--; 
                }
            }
        }

        return res;
    }
};
