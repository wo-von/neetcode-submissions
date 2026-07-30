class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, int> dp;
        dp.clear();
        vector<int>rob1V(nums.begin() + 1, nums.end());
        int rob1 = robDFS(rob1V, 0 , dp);
        dp.clear();
        vector<int>rob2V(nums.begin(), nums.end() - 1);
        int rob2 = robDFS(rob2V, 0, dp);
        return max(rob1, rob2);
    }

    int robDFS(vector<int>& nums, int index, unordered_map<int, int>& dp) {
        if (index >= nums.size())
            return 0;
        if (dp.count(index))
            return dp[index];
        int best = max(robDFS(nums, index + 1, dp), nums[index] 
            + robDFS(nums, index + 2, dp));
        dp[index] = best;
        return best;
    }
};
