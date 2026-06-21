class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.length() != t.length()) return false;
       unordered_map<char, int> count_s, count_t;
       for (int i = 0; i < s.length(); i++) {
        count_s[s[i]]++;
        count_t[t[i]]++;
       }
        return count_t == count_s;
    }
};
