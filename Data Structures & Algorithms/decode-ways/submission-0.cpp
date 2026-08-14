class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 0, prev1 = 1;
        for (int i = 1; i <= s.size(); i++) {
            int cur = 0;
            if (s[i-1] != '0') cur += prev1;
            if (i >= 2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) cur += prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
