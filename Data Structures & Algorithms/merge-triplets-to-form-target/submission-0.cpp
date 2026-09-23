class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = 0, b = 0, c = 0;
        for (auto& tri: triplets) {
            if (tri[0]>target[0] || tri[1]>target[1] || tri[2]>target[2])
            continue;
            a = max(a, tri[0]);
            b = max(b, tri[1]);
            c = max(c, tri[2]);
        }
        return (a==target[0] && b == target[1] && c == target[2]);
    }
};
