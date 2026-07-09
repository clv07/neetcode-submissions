class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // 1. find meeting point inside cycle
        do {
            slow = nums[slow];          // move one step
            fast = nums[nums[fast]];    // move two steps
        } while(slow != fast);

        // 2. find cycle entrance 
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
