class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];

        // record last occurence position of alphabet
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        int start = 0, end = 0;
        vector<int> res;

        for (int i = 0; i < s.size(); i++) {
            end = max(last[s[i] - 'a'], end); // update right boundary of current cut
            if (end == i) {     // window is self-contained
                res.push_back(end - start + 1);  // push the length of substring
                start = i + 1;
            }
        }

        return res;
    }
};
