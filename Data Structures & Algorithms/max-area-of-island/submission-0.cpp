class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 0;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    area = std::max(islandArea(grid, row, col), area);
                }
            }
        }
        return area;
    }
    int islandArea(vector<vector<int>>& grid, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();
        stack<pair<int, int>> st;
        st.push({row, col});
        grid[row][col] = 0;              // mark the seed too
        int area = 0;
        int hor[4] = {-1, 0, 1, 0};
        int ver[4] = {0, 1, 0, -1};
        while(!st.empty()){
            auto[x, y] = st.top(); st.pop();
            area++;
            for (int i = 0; i < 4; i++){
                int nx = x + hor[i], ny = y + ver[i];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                    continue;
                if (grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    st.push({nx, ny});
                }
            }
        }
        return area;
    }
};