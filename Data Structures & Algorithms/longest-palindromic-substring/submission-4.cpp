class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int bestLen = 1, bestStart = 0;
        for (int len = 2; len <= n; len++) {           // was len < n
            for (int start = 0; start + len - 1 < n; start++) {
                int l = start, r = start + len - 1;
                if (s[l] != s[r]) continue;
                if (len == 2 || dp[l + 1][r - 1]) {
                    dp[l][r] = 1;
                    if (len > bestLen) {               // moved inside the block
                        bestLen = len;
                        bestStart = start;
                    }
                }
            }
        }
        return s.substr(bestStart, bestLen);
    }
};