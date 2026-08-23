class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = 0;
        for (int j = n - 2; j >= 0; j--) {
            int end = min(nums[j] + j, n - 1);
            int minn = INT_MAX;
            for (int i = j + 1; i <= end; i++) {
                minn = min(minn, dp[i]);
            }
            dp[j] = (minn == INT_MAX) ? INT_MAX : minn + 1;
        }
        return dp[0];
    }
};