class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robDFS(nums, 0, memo);
    }

    int robDFS(vector<int>& nums, int i, vector<int>& memo){
        if (i >= nums.size()){
            return 0;
        }
        if(memo[i] != -1)
            return memo[i];
       int best = max(robDFS(nums, i + 1, memo), nums[i] + robDFS(nums, i + 2, memo));
        memo[i] = best;
        return best;
    }

};
