class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size(), cols = matrix[0].size();

        // first binary search
        int top = 0, bot = rows - 1, row = -1;
        while (top <= bot) {
            int m = top + (bot-top)/2;
            if (target < matrix[m][0]) bot = m - 1;
            else if (target > matrix[m][cols - 1]) top = m + 1;
            else {
                row = m;
                break;
            }
        }

        if (row == -1) return false;

        // second binary search
        int l = 0, r = cols - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (target < matrix[row][m]) r = m - 1;
            else if (target > matrix[row][m]) l = m + 1;
            else return true;
        }

        return false;
    }
};
