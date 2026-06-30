class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int u = ROWS*COLS-1, l = 0;
        int mid, row, col;
        while (l <= u){
            mid = l + (u - l) / 2;
            row = mid / COLS, col = mid % COLS;
            if (target == matrix[row][col]) return true;
            else if (target < matrix[row][col]){
                u = mid - 1;
            } else if (matrix[row][col] < target){
                l = mid + 1;
            }
        }
        return false;
    }
};
