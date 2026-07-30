class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int, pair<int,int>> dp;
        int best = INT_MIN;
        for (int i = 0; i < (int)nums.size(); i++)
            best = max(best, dfs(nums, i, dp).first);
        return best;
    }

    pair<int,int> dfs(vector<int>& nums, int i, unordered_map<int, pair<int,int>>& dp) {
        if (i == (int)nums.size() - 1)
            return {nums[i], nums[i]};
        if (dp.count(i)) return dp[i];
        auto [nmax, nmin] = dfs(nums, i + 1, dp);
        int a = nums[i] * nmax, b = nums[i] * nmin;
        dp[i] = { max({nums[i], a, b}), min({nums[i], a, b}) };
        return dp[i];
    }
};