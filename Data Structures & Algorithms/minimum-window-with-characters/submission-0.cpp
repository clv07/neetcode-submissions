class Solution {
public:
    string minWindow(string s, string t) {
        // validation check
        if (s.length() < t.length() || t.empty()) return "";

        unordered_map<char, int> need;
        for (char &c: t) need[c]++;
        int needCnt = need.size(); // distinct chars to satisfy

        unordered_map<char, int> window;
        int formedCnt = 0;                  // distinct chars currently satisfied
        int l = 0, minLen = INT_MAX, start=0; 

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) formedCnt++; // this char's count got fully met

            while (formedCnt == needCnt) {
                if (r-l+1 < minLen) {
                    minLen = r-l+1;
                    start = l; // remember where best window starts
                }
                char lc = s[l];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) formedCnt--; // dropped below requirement
                l++;
            }
        }

        return minLen == INT_MAX? "": s.substr(start, minLen);
    }
};
