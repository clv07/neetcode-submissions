class Solution {
public:

    string encode(vector<string>& strs) {
        // check if the string is empty
        if (strs.empty()) return "";

        string res;
        // record the size of each string, separated by comma and end with #
        for (string &s: strs) {
            res.append(to_string(s.size()));
            res.push_back(',');
        }
        res.push_back('#');

        // push the string to the result
        for (string &s: strs) {
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        // if the string is empty, return empty vector
        if (s.empty()) return {};

        // get the sizes of each string
        vector<int> sizes;
        int i = 0;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') j++;
            sizes.push_back(stoi(s.substr(i, j-i)));
            i = j + 1;
        }
        i++;

        // get the string
        vector<string> res;
        for (int sz: sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;

    }
};
