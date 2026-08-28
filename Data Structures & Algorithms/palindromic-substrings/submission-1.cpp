class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        if (n == 0) {
            return count;
        }
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
            count++;
        }
        for (int len = 2; len <=n; len++){
            for (int start = 0; start + len -1 < n; start++){
                int l = start, r = start + len -1;
                if (s[l] != s[r])
                    continue;
                if (len == 2 || dp[l+1][r-1]){
                    dp[l][r] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
