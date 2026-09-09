class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0], n = nums.size();
        for (int i = 1; i < n; i++) {
            num ^= nums[i];
        }
        return num;
    }
};
