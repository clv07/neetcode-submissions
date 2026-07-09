class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // value as the index, flag the number at the index as negative
        for (int i = 0; i < nums.size(); i++) {
            nums[abs(nums[i]) - 1] *= -1;
            int temp = nums[abs(nums[i]) - 1];
            if (temp > 0) return abs(nums[i]);
            
        }

    }
};
