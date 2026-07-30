class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int>dp;
        if (cost.size() == 1) {
            return cost[0];
        } else if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        int first = helperDFS(cost, 0, dp);
        int second = helperDFS(cost, 1, dp);
        return min(first, second);
    }
    int helperDFS(vector<int>& cost, int index, unordered_map<int, int>& dp){
        if (index >= cost.size()){
            return 0;
        }
        if (dp.count(index)){
            return dp[index];
        }
        int best = min(cost[index] + helperDFS(cost, index + 1, dp), 
            cost[index] + helperDFS(cost, index + 2, dp));
        dp[index] = best;
        return best;
    }
};
