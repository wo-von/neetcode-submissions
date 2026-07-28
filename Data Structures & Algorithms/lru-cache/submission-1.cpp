class LRUCache {
private:
    int capacity;
    vector<pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for (int i = 0; i < cache.size(); i++){
            if (cache[i].first == key){
                auto tmp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        bool found = false;
        for (int i = 0; i < cache.size(); i++){
            if (cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == this->capacity){
            cache.erase(cache.begin());
        }
        
        cache.push_back(pair(key, value));

        return;
    }
};
