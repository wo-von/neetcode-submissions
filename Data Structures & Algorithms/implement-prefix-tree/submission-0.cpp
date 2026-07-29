class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

    // Walk the tree following `s`; return the node we land on,
    // or nullptr if any char isn't present.
    TrieNode* traverse(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                return nullptr;
            curr = curr->children[idx];
        }
        return curr;
    }

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = traverse(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(const string& prefix) {
        return traverse(prefix) != nullptr;
    }
};