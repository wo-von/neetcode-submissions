class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> dict;
    int binary_search(vector<pair<int, string>>& v, int target){
    int l = 0;
    int r = (int)v.size() - 1;   
    int ans = -1;                
    while (l <= r){
        int m = l + (r - l) / 2;
        if (v[m].first <= target){
            ans = m;             
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}
public:
    TimeMap() {
        dict.clear();
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!dict.count(key))
            return "";
        int closest = binary_search(dict[key], timestamp);
        if (closest == -1) return "";
        return dict[key][closest].second;
    }
};
