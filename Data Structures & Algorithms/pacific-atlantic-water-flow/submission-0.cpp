class Solution {
private:
    vector<array<int,2>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<int>>& h, int i, int j, int prev,
             vector<vector<char>>& vis) {
        int rows = h.size(), cols = h[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols) return;
        if (vis[i][j]) return;
        if (h[i][j] < prev) return;        // can't climb downhill
        vis[i][j] = 1;
        for (auto& [dr, dc] : dirs)
            dfs(h, i + dr, j + dc, h[i][j], vis);   // current cell becomes prev
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        if (r == 0) return {};
        int c = heights[0].size();

        vector<vector<char>> pac(r, vector<char>(c, 0));
        vector<vector<char>> atl(r, vector<char>(c, 0));

        for (int i = 0; i < r; i++) {
            dfs(heights, i, 0,     INT_MIN, pac);   // left edge
            dfs(heights, i, c - 1, INT_MIN, atl);   // right edge
        }
        for (int j = 0; j < c; j++) {
            dfs(heights, 0,     j, INT_MIN, pac);   // top edge
            dfs(heights, r - 1, j, INT_MIN, atl);   // bottom edge
        }

        vector<vector<int>> res;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
        return res;
    }
};