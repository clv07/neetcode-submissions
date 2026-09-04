class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;

        for (int i = 0; i < n; i++) {
            if (i > reach) return false; // i unreachable, so is everything after it
            reach = max(reach, i + nums[i]); // absorb this index's jump
            if (reach >= n-1) return true; // early exit
        }

        return true;
    }
};
