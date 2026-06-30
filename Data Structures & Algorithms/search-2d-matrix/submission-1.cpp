class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r;
        int lower_row = 0;
        int upper_row = rows - 1;
        while(lower_row <= upper_row){
            r = lower_row + (upper_row - lower_row) / 2;
            if (matrix[r][cols - 1] < target){
                lower_row = r + 1;
            } else if (target < matrix[r][0]){
                upper_row = r - 1;
            } else break;
        }

        if (lower_row > upper_row) return false;
        int row = r;
        int l = 0;
        r = cols - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target){
                l = mid + 1;
            } else r = mid - 1;
        }
        return false;
    }
};
