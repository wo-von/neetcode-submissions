class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty())
            return "";

        unordered_map<char, int> ct;
        for (auto c : t)
            ct[c]++;

        string result = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string subs = s.substr(i, j - i + 1);
                unordered_map<char, int> sub_check;
                for (auto c : subs)
                    sub_check[c]++;

                bool valid = true;
                for (auto [key, val] : ct) {     
                    if (sub_check[key] < val) { valid = false; break; }
                }
                if (valid && (result.empty() || subs.size() < result.size()))
                    result = subs;
            }
        }
        return result;
    }
};