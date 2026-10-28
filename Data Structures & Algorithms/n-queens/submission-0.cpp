class Solution {
public:
    int n;
    vector<string> board;
    vector<int> diag, anti, col;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, string(n, '.'));
        diag.assign(2*n - 1, false);
        anti.assign(2*n - 1, false);
        col.assign(n, false);
        backtrack(0);
        return res;
    }

    void backtrack(int r) {
        if (r == n) { // base case: all n rows filled
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            int d = r - c + n - 1;
            if (col[c] || diag[d] || anti[r+c]) continue;

            board[r][c] = 'Q'; // choose
            col[c] = true; diag[d] = true; anti[r+c] = true;
            backtrack(r+1);
            board[r][c] = '.'; // undo
            col[c] = false; diag[d] = false; anti[r+c] = false;
        }
    }
};
