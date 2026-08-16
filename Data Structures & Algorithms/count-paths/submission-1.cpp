class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);

        for (int i = 0; i < m-1; i++) {
            vector<int> curr(n, 1);
            for (int j = n-2; j >= 0; j--) 
                curr[j] = prev[j] + curr[j+1];
            prev = curr;
        }

        return prev[0];
    }
};
