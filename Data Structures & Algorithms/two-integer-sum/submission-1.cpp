class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (visited.count(diff) && visited[diff] != i)
                return {visited[diff], i};
            visited[nums[i]] = i;
        }
        return {};
    }
};
