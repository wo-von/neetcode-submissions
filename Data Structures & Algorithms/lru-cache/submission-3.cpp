class LRUCache {
private:
    int capacity;
    list<pair<int, int>> items;                          // front = MRU, back = LRU
    unordered_map<int, list<pair<int, int>>::iterator> pos;  // key -> node

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        items.splice(items.begin(), items, it->second);  // move node to front, O(1)
        return it->second->second;                       // iterator -> pair -> value
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;                  // update value in place
            items.splice(items.begin(), items, it->second);
            return;
        }
        if ((int)items.size() == capacity) {
            pos.erase(items.back().first);               // evict LRU key from map
            items.pop_back();                            // ...and from list
        }
        items.push_front({key, value});
        pos[key] = items.begin();
    }
};