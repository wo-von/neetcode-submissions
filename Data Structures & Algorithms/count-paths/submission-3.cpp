class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n, -1));
        return dfs(paths, m , n, 0, 0);     
    }
    int dfs(vector<vector<int>>& paths, int m, int n, int i, int j){
        if (i == m - 1 && j == n - 1)
            return 1;
        if ( i >= m || j >= n)
            return 0;
        if (paths[i][j] != -1){
            return paths[i][j];
        }
        return paths[i][j] = dfs(paths, m , n, i + 1, j) + dfs(paths, m, n, i , j + 1);
        
    }
};
