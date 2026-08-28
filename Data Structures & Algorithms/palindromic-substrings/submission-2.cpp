class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (s.empty())
            return n;
        int count = n;
        for (int i = 0; i < n; i++) {
            // even
            int l = i, r = l + 1;
            while(l >= 0 && r <= n - 1 && s[l] == s[r]) {
                count++;
                l--, r++;
            }
            // odd
            l = i - 1, r = i + 1;
            while(l >= 0 && r <= n - 1 && s[l] == s[r]) {
                count++;
                l--, r++;
            }
        }
        return count;
    }
};
