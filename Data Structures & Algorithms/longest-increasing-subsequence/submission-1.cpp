class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return lengthDFS(nums, 0, -1, memo);
    }
    int lengthDFS(vector<int>& nums, int i, int j, vector<vector<int>>& memo){
        if ( i == nums.size())
            return 0;
        if (memo[i][j + 1] != -1)
            return memo[i][j+1];
        int result = lengthDFS(nums, i + 1, j, memo);
        if (j == -1 || nums[j] < nums[i]){
            result = max(result, 1 + lengthDFS(nums, i + 1, i, memo));
        }
        memo[i][j+1] = result;
        return result;
    }
};
