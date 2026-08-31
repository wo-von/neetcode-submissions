class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = mp.find(key);                 // fix 1: no silent insert
        if (it == mp.end()) return "";
        const auto& v = it->second;

        int l = 0, r = (int)v.size() - 1;       // fix 2: cast before -1
        int best = -1;                          // fix 4/5: converged index, not stale mid
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= timestamp) {    // fix 3: predicate satisfied
                best = mid;                     // candidate — better one may be right
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return best == -1 ? "" : v[best].second;
    }
};