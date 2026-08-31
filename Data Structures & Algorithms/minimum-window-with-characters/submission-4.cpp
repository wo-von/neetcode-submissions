class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty()){
            return "";
        }
        unordered_map<char, int> tm;
        for (auto& c: t){
            tm[c]++;
        }
        int need = tm.size(), have = 0;
        int res_left = 0, res_right =(int)s.size() - 1;
        int length = INT_MAX;
        unordered_map<char, int>checker;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            char curr = s[r];
            checker[curr]++;
            if (tm.count(curr) && checker[curr] == tm[curr]){
                have++;
            }
            // we have seen all we need, start shrinking the window
            while (need == have){
                if (r - l + 1 < length){
                res_left = l, res_right = r, length = r - l + 1;
                }
                checker[s[l]]--;
                if (checker.count(s[l]) &&checker[s[l]] < tm[s[l]]){
                    have--;
                }
                l++;
            }
            
        }
        return (length < INT_MAX) ? s.substr(res_left, length) : "";
    }
};
