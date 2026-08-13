class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += palindrome(s, i, i);
            count += palindrome(s, i, i+1);
        }
        return count;
    }

    int palindrome(const string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};
