class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // maintain a fixed sized window (s1 length)
        // slide over s2 and check if all the char exist with same freq in s1


        // validation check if s1 longer than s2
        if (s1.size() > s2.size()) return false;

        vector<int> s1c(26,0), s2c(26,0);
        int n = s1.size();

        // build initial window
        for (int i=0; i<n; i++) {
            s1c[s1[i]-'a']++;
            s2c[s2[i]-'a']++;
        }
        if (s1c == s2c) return true;

        // slide the window
        for (int r=n; r< s2.size(); r++) {
            s2c[s2[r] - 'a']++; 
            s2c[s2[r-n] - 'a']--; // remove char freq from the left
            if (s1c == s2c) return true;
        }
        return false;
    }
};
