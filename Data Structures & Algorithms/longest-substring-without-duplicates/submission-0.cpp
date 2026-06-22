class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // intuition:
        // keep the sliding window [start, i] without duplicate
        // when a character repeated, jump foward the  `start` to past its previous occurence

        int longest=0, start=0;
        unordered_map<char, int> loc; // store last index seen this char

        for (int i=0; i<s.size(); i++) {
            if (loc.count(s[i])) 
                start = max(start, loc[s[i]]+1);  // jump forward start
            loc[s[i]] = i;                      // update to newest index
            longest = max(longest, i-start+1);  // calculate the longest substring
        }

        return longest;
    }
};
