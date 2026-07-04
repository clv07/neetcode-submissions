class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bot = rows - 1;
        while (top <= bot) {
            int row = (top + bot) / 2;
            if (matrix[row][cols - 1] < target) top = row + 1;
            else if (matrix[row][0] > target) bot = row - 1;
            else break;
        }        

        if (!(top <= bot)) return false;

        int row = (top + bot) / 2;
        int l = 0, r = cols - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if (matrix[row][m] < target) l = m + 1; 
            else if (matrix[row][m] > target) r = m - 1;
            else return true;
        }

        return false;
    }
};
