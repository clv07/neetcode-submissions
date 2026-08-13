class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, len);   // odd length
            expand(s, i, i+1, start, len); // even length
        }
        return s.substr(start, len);
    }

    void expand(const string& s, int l, int r, int& start, int& len) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        int curLen = r - l - 1;
        if (curLen > len) {
            len = curLen;
            start = l + 1;
        }
    }
};
