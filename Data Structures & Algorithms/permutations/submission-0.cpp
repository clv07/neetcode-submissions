class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int &n: nums) {
            vector<vector<int>> next; // fresh generation
            for (auto& p: res) {
                for (int j = 0; j <= p.size(); j++) {
                    vector<int> copy = p;
                    copy.insert(copy.begin() + j, n);
                    next.push_back(std::move(copy));
                }
            }
            res = std::move(next); //replace
        }

        return res;
    }
};
