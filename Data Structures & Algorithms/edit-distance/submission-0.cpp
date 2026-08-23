class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> memo(l1, vector<int>(l2, -1));
        return distance(word1, word2, 0, 0, memo);
    }

    int distance(string& w1, string& w2, int i, int j, vector<vector<int>>& memo) {
        if (i == (int)w1.size()) return (int)w2.size() - j;
        if (j == (int)w2.size()) return (int)w1.size() - i;
        if (memo[i][j] != -1) return memo[i][j];

        int res;
        if (w1[i] == w2[j]) {
            res = distance(w1, w2, i + 1, j + 1, memo);
        } else {
            res = 1 + min({distance(w1, w2, i + 1, j,     memo),   // delete
                           distance(w1, w2, i + 1, j + 1, memo),   // substitute
                           distance(w1, w2, i,     j + 1, memo)}); // insert
        }
        return memo[i][j] = res;
    }
};