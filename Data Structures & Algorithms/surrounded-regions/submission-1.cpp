class Solution {
public:
    int m,n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // left and right
        for (int r = 0; r < m; r++) {
            dfs(board, r, 0);
            dfs(board, r, n-1);
        }

        // up and bottom
        for (int c = 0; c < n; c++) {
            dfs(board, 0, c);
            dfs(board, m-1, c);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
        
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (board[r][c] != 'O') return; 

        board[r][c] = '#'; // mark the reachable 'O' as '#'
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};
