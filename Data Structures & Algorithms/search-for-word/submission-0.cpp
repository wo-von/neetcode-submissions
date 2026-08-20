class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        if (word.empty()) return true;

        vector<vector<char>> visited(rows, vector<char>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (word_searcher(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool word_searcher(vector<vector<char>>& board, const string& word,
                       vector<vector<char>>& visited, int i, int j, int index) {
        static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int rows = board.size();
        int cols = board[0].size();

        // reject: off-board, already on the path, or wrong character
        if (i < 0 || i >= rows) return false;
        if (j < 0 || j >= cols) return false;
        if (visited[i][j] == 1) return false;
        if (board[i][j] != word[index]) return false;

        // this cell matched and it was the last one
        if (index + 1 == (int)word.size()) return true;

        visited[i][j] = 1;                              // choose
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (word_searcher(board, word, visited, ni, nj, index + 1)) {
                return true;
            }
        }
        visited[i][j] = 0;                              // un-choose

        return false;
    }
};