class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> duplicate;
        for (int n: nums) {
            if (duplicate.contains(n))
                return true;
            duplicate.insert(n);
        }
        return false;
    }
};