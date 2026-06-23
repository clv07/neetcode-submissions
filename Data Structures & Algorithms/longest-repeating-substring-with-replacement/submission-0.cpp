class Solution {
public:
    int characterReplacement(string s, int k) {
        // valid window condition:
        // window length - count of most frequent char in window  <=k 
        // left and right ptr remain a valid window
        // a vector keep track frequency of char
        // if window is not valid anymore, move left ptr, else move right ptr
        
        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;
        for (int r=0; r<s.size(); r++) {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']); //most frequent char count
            
            // if characters to replace exceeds k, move left ptr
            while ((r-l+1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};
