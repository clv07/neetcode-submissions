// update cell: increment 1 if any operation
// cell movement: 
// 1. move cell down by 1 - move right one character in word1
// 2. move cell right by 1 - move right one character in word2

class Solution {
public:
    int minDistance(string word1, string word2) {
        // row as word 1, col as word 2
        int rows = word1.size(), cols = word2.size();

        // dp[r][c] = min operations to turn word[0...r) to word2[0...c)
        vector<vector<int>> dp(rows+1, vector<int>(cols+1)); 

        // base case: empty string does not need any operation, and other have number of operation equals to the index
        for (int r = 0; r <= rows; r++) dp[r][0] = r; // insert all r chars
        for (int c = 0; c <= cols; c++) dp[0][c] = c; // insert all c chars
        
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                if (word1[r-1] == word2[c-1]) // match
                    dp[r][c] = dp[r-1][c-1];
                else 
                    dp[r][c] = 1 + min({
                        dp[r-1][c],  // delete
                        dp[r][c-1],  // insert
                        dp[r-1][c-1] // replace
                        }); 
            }
        }

        return dp[rows][cols];


    }
};
