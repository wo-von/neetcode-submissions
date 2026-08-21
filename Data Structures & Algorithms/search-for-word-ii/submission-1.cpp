class TrieNode {
public:
    TrieNode* children[26];
    string word;                    // non-empty ⇒ this node ends a word
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Dictionary {
public:
    TrieNode* root;
    Dictionary() {
        root = new TrieNode;
    }
    void insert(const string& word) {
        TrieNode* curr = root;
        for (auto& c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode;
            }
            curr = curr->children[c - 'a'];
        }
        curr->word = word;
    }
};

class Solution {
    int rows;
    int cols;
    static constexpr int prox[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = (int)board.size();
        cols = (int)board[0].size();

        Dictionary dict;
        for (auto& w : words) {
            dict.insert(w);
        }

        vector<string> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, dict.root, i, j, ans);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j,
             vector<string>& ans) {
        if (i < 0 || i >= rows) return;
        if (j < 0 || j >= cols) return;

        char c = board[i][j];
        if (c == '#') return;                       // already on the current path

        TrieNode* next = node->children[c - 'a'];
        if (next == nullptr) return;                // no word continues this way

        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word.clear();                     // collect once, never again
        }

        board[i][j] = '#';                          // choose
        for (auto& p : prox) {
            dfs(board, next, i + p[0], j + p[1], ans);
        }
        board[i][j] = c;                            // un-choose
    }
};