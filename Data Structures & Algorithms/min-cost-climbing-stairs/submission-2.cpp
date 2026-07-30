class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(helperDFS(cost, 0, dp), helperDFS(cost, 1, dp));
    }
    int helperDFS(vector<int>& cost, size_t index, vector<int>& dp) {
        if (index >= cost.size()) return 0;
        if (dp[index] != -1) return dp[index];
        dp[index] = cost[index] + min(helperDFS(cost, index + 1, dp),
                                      helperDFS(cost, index + 2, dp));
        return dp[index];
    }
};