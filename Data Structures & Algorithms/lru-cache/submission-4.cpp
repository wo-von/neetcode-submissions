class LRUCache {
private:
    using Order = list<int>;
    using Dict = unordered_map<int, pair<int, Order::iterator>>;
    int cap;
    Order order;
    Dict dict;
public:
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        auto it = dict.find(key);
        if (it == dict.end()) {
            return -1;
        }
        order.splice(order.end(), order, it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = dict.find(key);
        if (it != dict.end()) {
            it->second.first = value;
            order.splice(order.end(), order, it->second.second);
            return;
        }
        if (static_cast<int>(dict.size()) == cap) {
            int lru = order.front();
            order.pop_front();
            dict.erase(lru);
        }
        order.push_back(key);
        dict[key] = {value, prev(order.end())};
    }
};