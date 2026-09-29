class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;

        vector<unsigned long long> dp(n+1, 0);
        dp[n] = 1;
    
        for (int i = m-1; i >= 0; i--)
            for (int j = 0; j < n; j++) // left to right
                if (s[i] == t[j]) dp[j] += dp[j+1]; // skip is implicit; add "use"

        return dp[0];
    }
};
