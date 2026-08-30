class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size() + 1, -1);
        dp.back() = 1;
        return dfs(s, 0, dp);
    }
    int dfs(string& s, int index, vector<int>& dp) {
        if (index == s.size()){
            return dp[index];
        }
        if (dp[index] != -1){
            return dp[index];
        }
        int dig_1 = 0, dig_2 = 0;
        // take one digit
        if (s[index] != '0'){
            dig_2 = dfs(s, index + 1, dp);
        }
        // take 2 digits
        if (index + 1 < s.size() && (s[index] == '1' || (s[index] == '2'
            && s[index+1] <= '6'))){
            dig_1 = dfs(s, index + 2, dp);
        }
        return dp[index] = dig_1 + dig_2; 
    }
};
