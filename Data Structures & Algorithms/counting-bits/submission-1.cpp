class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = n; i > 0; i--) {
            if (dp[i] != -1) continue;      // already known, nothing to do

            int counter = 0;
            int copy = i;
            while (copy > 0) {
                counter += copy & 1;
                copy >>= 1;
            }
            dp[i] = counter;

            if (i % 2) {
                dp[i / 2] = counter - 1;    // odd: dropping the low 1-bit loses a bit
            } else {
                dp[i / 2] = counter;        // even: low bit was 0, nothing lost
            }
        }
        return dp;
    }
};