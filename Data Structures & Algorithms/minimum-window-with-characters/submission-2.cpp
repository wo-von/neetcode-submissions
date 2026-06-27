class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size())
            return "";
        unordered_map<char, int> t_checker, window_checker;
        for (auto& c: t)
            t_checker[c]++;
        int need = t_checker.size();
        int have = 0;
        int reslen = INT_MAX;
        pair<int, int>res = {-1 , -1};
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            char c = s[r];
            window_checker[c]++;
            if (t_checker.count(c) 
                && window_checker[c] == t_checker[c]){
                    have++;
                }

            while (need == have){
                if ((r - l + 1) < reslen){
                    reslen = r - l + 1;
                    res = {l, r};
                }
                window_checker[s[l]]--;
                if (t_checker.count(s[l]) 
                    && window_checker[s[l]] < t_checker[s[l]]){
                        have--;
                    }
                l++;
            }
        }
        return reslen == INT_MAX ? "" : s.substr(res.first, reslen);
    }
};
