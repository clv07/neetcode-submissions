class Solution {
public:
    int jump(vector<int>& nums) {
        // BFS
        int  n = nums.size();
        int jump = 0;
        int curEnd = 0; // right edge of current level
        int farthest = 0;   // best reach found while scanning this level
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) { // finished this level
                ++jump;
                curEnd = farthest; // next level's boundary
            }
        }
        return jump;
    }
};
