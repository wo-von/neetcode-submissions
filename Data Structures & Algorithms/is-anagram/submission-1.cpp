class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.length() != t.length()) return false;
       unordered_multiset<char> set_s, set_t;
       for (char c : s) set_s.insert(c);
       for (char c : t) set_t.insert(c);
       for (char c : set_t){
        if (set_t.count(c) != set_s.count(c)) return false;
       } 
       return true;
    }
};
