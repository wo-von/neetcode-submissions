class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEOW = false;                       // default-initialized
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEOW = true;                   // AFTER the loop — only the final node
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    TrieNode* root;

    bool dfs(const string& word, int index, TrieNode* node) {
        for (int i = index; i < (int)word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                
                if (!node->children.count(c))
                    return false;
                node = node->children[c];
                //auto it = node->children.find(c);
                //if (it == node->children.end()) return false;
                //node = it->second;            // descend into the child, then continue
            } else {
                for (auto& [_, child] : node->children)
                    if (dfs(word, i + 1, child)) return true;   // try every child
                return false;                 // no child led to a match
            }
        }
        return node->isEOW;
    }
};