class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right) {
            // 1. left to right along top row
            for (int c = left; c <= right; c++) 
                res.push_back(matrix[top][c]);
            top++;
            
            // 2. top to bottom along right column
            for (int r = top; r <= bottom; r++)
                res.push_back(matrix[r][right]);
            right--;

            // 3. right to left along bottom row only if a row remains
            if (top <= bottom) {
                for (int c = right; c >= left; c--)
                    res.push_back(matrix[bottom][c]);
                bottom--;
            } 

            // 4. bottom to top along left column if a column remains
            if (left <= right) {
                for (int r = bottom; r >= top; r--)
                    res.push_back(matrix[r][left]);
                left++;
            }
        }

        return res;
    }
};
