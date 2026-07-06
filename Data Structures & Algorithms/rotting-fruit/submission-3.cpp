class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> qu;
        int rows = grid.size();
        int cols = grid[0].size();
        // enqueue all initially rotten oranges
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 2)
                    qu.push({row, col, 0});
            }
        }
        int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minute = 0;
        while(!qu.empty()){
            auto[x, y, m] = qu.front(); qu.pop();
            for (int i = 0; i < 4; i++){
                int this_x = x + neigh[i][0];
                int this_y = y + neigh[i][1];
                if (this_x < 0 || this_x >= rows
                    || this_y < 0 || this_y >= cols)
                    continue;
                if (grid[this_x][this_y] == 1){
                    grid[this_x][this_y] = 2;
                    qu.push({this_x, this_y, m + 1});
                    minute = std::max(m + 1, minute);
                }
            }
        }
        // check if any fresh fruit remains
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return minute;
    }
};