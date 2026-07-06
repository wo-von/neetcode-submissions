class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int counter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0')
                    continue;
                islandDFS(grid, i, j);
                counter++;                    // count here, not inside DFS
            }
        }
        return counter;
    }

    void islandDFS(vector<vector<char>>& grid, int row, int column) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        stack<pair<int, int>> st;
        st.push({row, column});
        grid[row][column] = '0';              // mark on push

        while (!st.empty()) {
            auto [i, j] = st.top(); st.pop();
            for (int d = 0; d < 4; d++) {
                int m = i + dr[d];
                int n = j + dc[d];
                if (m < 0 || m >= rows || n < 0 || n >= cols)
                    continue;
                if (grid[m][n] == '1') {
                    grid[m][n] = '0';         // mark visited when pushing
                    st.push({m, n});
                }
            }
        }
    }
};