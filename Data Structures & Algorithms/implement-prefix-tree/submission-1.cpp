class TrieNode {
public:
    TrieNode* node[26];
    bool isWord;
    TrieNode(){
        for (size_t i = 0 ; i < 26; i++){
            node[i] = nullptr;
        }
        isWord = false;
    }
};


class PrefixTree {
private:
    TrieNode* root;
    TrieNode* walk_trie (string word) {
        TrieNode* curr = root;
        for (auto c: word){
            size_t index = c - 'a';
            if (curr->node[index] == nullptr) {
                return nullptr;
            }
            curr = curr->node[index];
        }
        return curr;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto c: word){
            size_t index = c - 'a';
            if (curr->node[index] == nullptr){
                TrieNode* next = new TrieNode();
                curr->node[index] = next;
                curr = next;
            } else {
                curr = curr->node[index];
            }
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* result = walk_trie(word);
        if (result != nullptr){
            if (result->isWord) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* result = walk_trie(prefix);
        if (result != nullptr){
            return true;
        } else {
            return false;
        }
    }
};
