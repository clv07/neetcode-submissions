class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) return m;
           
            if (nums[m] <= nums[r]) { // if right half is sorted
                if (nums[m] < target && target <= nums[r]) // target in sorted right
                    l = m + 1; 
                else 
                    r = m - 1; // else left
            } 
            else { // if left half is sorted
                if (nums[l] <= target && target < nums[m]) // target in sorted left
                    r = m - 1;
                else 
                    l = m + 1; // else right
            }
        }

        return -1;

    }
};
