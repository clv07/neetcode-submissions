class Solution {
public:

    string encode(vector<string>& strs) {
        // check if the string is empty
        if (strs.empty()) return "";

        string res;
        for (string &s: strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        // if the string is empty, return empty vector
        if (s.empty()) return {};

        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            
            i = j + 1;
            j = i + len;
            res.push_back(s.substr(i, len));
            i = j;
        }

        return res;

    }
};
