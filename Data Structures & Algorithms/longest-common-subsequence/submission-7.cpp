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

        int& res = memo[i][j];
        if (res != -1) return res;

        // take s[i]: match it at its earliest possible spot in l
        int take = 0;
        size_t pos = l.find(s[i], j);
        if (pos != string::npos) {
            take = 1 + dfs(s, l, i + 1, (int)pos + 1, memo);
        }

        // don't take s[i]
        int skip = dfs(s, l, i + 1, j, memo);

        res = max(take, skip);
        return res;
    }
};