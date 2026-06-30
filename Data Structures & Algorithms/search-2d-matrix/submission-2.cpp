class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Pass 1: find the row whose range [first, last] could hold target.
        int top = 0, bottom = rows - 1, row = -1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (target < matrix[mid][0]) {
                bottom = mid - 1;
            } else if (target > matrix[mid][cols - 1]) {
                top = mid + 1;
            } else {
                row = mid;          // target falls within this row's range
                break;
            }
        }
        if (row == -1) return false;

        // Pass 2: binary search within that row.
        int l = 0, r = cols - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};