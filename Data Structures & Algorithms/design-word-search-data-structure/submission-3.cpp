class WordDictionary {
    struct Node {
        Node* children[26] = {};
        bool isEnd = false;
    };
    Node* root = new Node();

public:
    void addWord(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(const string& word) {
        vector<Node*> frontier = {root};      // all nodes still alive so far
        for (char c : word) {
            vector<Node*> next;
            for (Node* node : frontier) {
                if (c == '.') {                // wildcard: fan out to every child
                    for (int i = 0; i < 26; i++)
                        if (node->children[i]) next.push_back(node->children[i]);
                } else {                       // fixed char: at most one child
                    int i = c - 'a';
                    if (node->children[i]) next.push_back(node->children[i]);
                }
            }
            if (next.empty()) return false;
            frontier = move(next);
        }
        for (Node* node : frontier)            // accept if any survivor ends a word
            if (node->isEnd) return true;
        return false;
    }
};