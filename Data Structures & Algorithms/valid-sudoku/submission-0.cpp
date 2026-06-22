class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = 9;
        vector<int> check(n+1, 0);
        // check row
        for (int i = 0; i <= n-1; i++) {
            for (int j = 0; j <=n-1; j++) {
                if(isdigit(board[i][j])) {
                    int idx = board[i][j] - '0';
                    check[idx]++;
                    if (check[idx] > 1) return false;
                }
            }
            fill(check.begin(), check.end(), 0);
        }

        // check column
        for (int i = 0; i <= n-1; i++) {
            for (int j = 0; j <=n-1; j++) {
                if(isdigit(board[j][i])) {
                    int idx = board[j][i] - '0';
                    check[idx]++;
                    if (check[idx] > 1) return false;
                }
            }
            fill(check.begin(), check.end(), 0);
        }

        // check grid
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            fill(check.begin(), check.end(), 0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[boxRow + i][boxCol + j];
                    if (isdigit(c)) {
                        int idx = c - '0';
                        if (++check[idx] > 1) return false;
                    }
                }
            }
        }
    }
        
        return true;

    }
};
