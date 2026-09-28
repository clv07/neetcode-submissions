class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m+n != s3.size()) return false;
        if (n > m) return isInterleave(s2, s1, s3); // keep the row the shorter string

        vector<bool> dp(n + 1, false);
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i == m && j == n) { // initialize
                    dp[j] = true;
                    continue;
                }

                bool fromS1 = i < m && s1[i] == s3[i+j] && dp[j]; // dp[j] = old row (i+1)
                bool fromS2 = j < n && s2[j] == s3[i+j] && dp[j+1]; // dp[j+1] = current row
                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[0];
    }
};
