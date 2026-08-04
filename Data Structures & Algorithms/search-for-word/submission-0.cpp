class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& b, const string& w, int r, int c, int k) {
        // base cases
        if (k == w.size()) return true;
        if (r < 0 || r >= b.size() || c < 0 || c >= b[0].size()) return false; // out of bounds
        if (b[r][c] != w[k]) return false; // mismatch character

        // backtracking
        char saved = b[r][c];
        b[r][c] = '#';
        bool found = dfs(b, w, r+1, c, k+1) || dfs(b, w, r, c+1, k+1) || dfs(b, w, r-1, c, k+1) || dfs(b, w, r, c-1, k+1); // go left, right, up and down 
        b[r][c] = saved; // restore
        return found;
    }
};
