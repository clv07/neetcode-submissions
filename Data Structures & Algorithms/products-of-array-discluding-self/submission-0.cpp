class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix;
        vector<int> suffix;
        vector<int> result;

        int product = 1;
        prefix.push_back(product);
        for (size_t i = 0; i < N-1; i++) {
            product *= nums[i];
            prefix.push_back(product);
        }

        product = 1;
        suffix.push_back(product);
        for (size_t i = N-1; i > 0; i--) {
            product *= nums[i];
            suffix.push_back(product);
        }

        for (size_t i=0; i < N; i++) {
            result.push_back(prefix[i] * suffix[N-i-1]);
        }

        return result;

    }
};
