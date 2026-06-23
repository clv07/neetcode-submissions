class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // maintain a fixed sized window (s1 length)
        // slide over s2 and check if all the char exist with same freq in s1

        // validation check if s1 longer than s2
        if (s1.size() > s2.size()) return false;

        vector<int> s1c(26,0), s2c(26,0);
        int n = s1.size(), matches=0;

        // build initial window
        for (int i=0; i<n; i++) {
            s1c[s1[i]-'a']++;
            s2c[s2[i]-'a']++;
        }
        
        // check matching
        for (int i=0; i<26; i++) {
            if (s1c[i] == s2c[i]) matches++;
        }

        // slide the window
        for (int r=n; r< s2.size(); r++) {
            if (matches == 26) return true;

            int idx = s2[r] - 'a';
            s2c[idx]++; 
            if (s1c[idx] == s2c[idx]) matches++;
            else if (s1c[idx] + 1 == s2c[idx]) matches--;

            idx = s2[r-n] - 'a';
            s2c[idx]--; // remove char freq from the left
            if (s1c[idx] == s2c[idx]) matches++;
            else if (s1c[idx] - 1 == s2c[idx]) matches--;
            
        }
        return matches == 26;
    }
};
