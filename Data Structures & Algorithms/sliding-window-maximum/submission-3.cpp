class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && nums[dq.back()] <= nums[r]) dq.pop_back(); // these values can never be max again
            dq.push_back(r);
            if (dq.front() <= r-k) dq.pop_front(); // remove out of window index
            if (r >= k-1) res.push_back(nums[dq.front()]); // start pushing max value once the first valid sliding window done forming 
        }
        return res;
    }
};
