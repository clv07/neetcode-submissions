class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // left and right pointer
        int l = 0; 
        int r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] > target) r--;
            if (numbers[l] + numbers[r] < target) l++;
            if (numbers[l] + numbers[r] == target) break;
        }

        return {l+1, r+1};
    }
};
