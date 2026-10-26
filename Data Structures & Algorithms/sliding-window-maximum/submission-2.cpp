class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // intuition:
        // find the max in the window, record its position and value
        // as long as the value is still in the window, move window to the right and compare with the rightmost value
        // if rightmost value is larger, update position and value
        // if the max value dropped out from the valid window, do a loop within the loop to find a new max value

        int maxVal = INT_MIN, pos = -1; // max value within window
        vector<int> res;
        for (int r = k - 1; r < nums.size(); r++) {
            int l = r - k + 1;
            if (pos < l) { 
                maxVal = INT_MIN;
                for (int i = l; i <= r; i++){
                    if (maxVal <= nums[i]) {
                        maxVal = nums[i];
                        pos = i;
                    }
                }
            } else if (maxVal < nums[r]){
                maxVal = nums[r];
                pos = r;
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
