class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) 
            return false;
        for (int i = 0; i < s.length(); i++) {
            size_t pos = t.find(s[i]);
            if (pos != std::string::npos){
                t.erase(pos, 1);
                s.erase(i, 1);
                i--;
            }
        }

        return s == "" && t == "";
    }
};
