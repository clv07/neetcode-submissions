class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // i is index in s
        // j is index in p
        dp[m][n] = true; // base case: empty string matched empty pattern
        for (int i = m; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                // match if the pattern is '.' or both have same character
                bool match = i < m && (p[j] == '.' || p[j] == s[i]);

                if ((j+1) < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2]; // skip the pattern
                    if (match) 
                        dp[i][j] = dp[i][j] || dp[i+1][j]; // continue matching character in s
                }
                else if (match) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];

    }
};
