class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value): key(key), value(value), next(nullptr), prev(nullptr) {} 
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    void remove(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        p->next= n;
        n->prev = p;
        return;
    }
    // insert at the end, since everything inserted is also newest
    void insert(Node* node){
        Node* last = right->prev;
        last->next = node;
        node->prev = last;
        node->next = right;
        right->prev = node;
        return;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            cache[key]->value = value;
            remove(cache[key]);
            insert(cache[key]);
            return;
        }
        if (cache.size()>= cap){
            Node* first = left->next;
            remove(first);
            cache.erase(first->key);
            delete first;
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        return;
    }
};
