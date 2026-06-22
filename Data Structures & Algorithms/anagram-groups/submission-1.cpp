class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> group;

        for (string &s: strs) {
            int count[26] = {0};
            for (char c: s)
                count[c - 'a']++;
            string key;
            for (int c: count) 
                key += "#" + to_string(c);
            group[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &[key, g]: group)
            result.push_back(g);

        return result;
    }
};
