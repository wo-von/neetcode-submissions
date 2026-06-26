class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> checker;

        int length = 0;
        int l = 0;
        for (int r = 0; r<s.size(); r++){
            while (checker.find(s[r]) != checker.end()){
                checker.erase(s[l]);
                l++;
            }
            checker.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }
};
