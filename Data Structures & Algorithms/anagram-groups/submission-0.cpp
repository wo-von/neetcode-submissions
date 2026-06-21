class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s: strs) {
            vector<int> count(26, 0);
            for (auto c: s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> final;
        for (const auto& kv: res){
            final.push_back(kv.second);
        }
        return final;
    }
};
