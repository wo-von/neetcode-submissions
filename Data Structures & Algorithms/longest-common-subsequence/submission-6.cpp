class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dfs(text1, text2, 0, 0, memo);
    }

private:
    int dfs(const string& s, const string& l, int i, int j,
            vector<vector<int>>& memo) {
        if (i == (int)s.size() || j == (int)l.size()) return 0;

        int& res = memo[i][j];          // bind once, read and write through it
        if (res != -1) return res;

        if (s[i] == l[j]) {
            res = 1 + dfs(s, l, i + 1, j + 1, memo);
        } else {
            res = max(dfs(s, l, i + 1, j, memo),
                      dfs(s, l, i, j + 1, memo));
        }
        return res;
    }
};