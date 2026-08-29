auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class LRUCache {
    using Order = list<int>;
    using Dict  = unordered_map<int, pair<int, Order::iterator>>;

    int cap_;
    Order order_;   // front = LRU, back = MRU
    Dict  dict_;    // key -> {value, node in order_}

    void touch(Dict::iterator it) {
        order_.splice(order_.end(), order_, it->second.second);
    }

public:
    LRUCache(int capacity) : cap_(capacity) {}

    int get(int key) {
        auto it = dict_.find(key);
        if (it == dict_.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = dict_.find(key);
        if (it != dict_.end()) {
            it->second.first = value;
            touch(it);
            return;                     // size unchanged -> nothing to evict
        }
        if (static_cast<int>(dict_.size()) == cap_) {
            int lru = order_.front();   // the key itself
            order_.pop_front();
            dict_.erase(lru);
        }
        order_.push_back(key);
        dict_[key] = {value, prev(order_.end())};
    }
};