class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if (n == 0 || m == 0)
            return 0;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return dfs(text1, text2, 0, 0, dp);
    }

    int dfs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= s1.size() || j >= s2.size())
            return 0;
        int& r = dp[i][j];
        if (r != -1)
            return r;
        int take = 0;
        auto it = s2.find(s1[i], j);
        if (it != string::npos) {
            take = 1 + dfs(s1, s2, i + 1, (int)it + 1, dp);
        }
        int skip = dfs(s1, s2, i + 1, j, dp);
        r = max(take, skip);
        return r;
    }
};
