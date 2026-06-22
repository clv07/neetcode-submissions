class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> duplicate;
        for (int n: nums) {
            duplicate.insert(n);
        }
        return duplicate.size() != nums.size();
    }
};