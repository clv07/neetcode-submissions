class Solution {
public:
    bool isPalindrome(string s) {
        // check if the string is empty
        if (s.empty() || s.size() == 1) return true;

        // define 2 pointers - one at beginning, one at the end.
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }
       
        return true;
    }
};
