class Solution {
public:
    int jump(vector<int>& nums) {
        unordered_map<int, int> memo;
        return dfs(nums, 0, memo);
    }

private:
    int dfs(vector<int>& nums, int i, unordered_map<int, int>& memo) {
        if (memo.count(i)) {
            return memo[i];
        }
        if (i == nums.size() - 1) {
            return 0;
        }
        if (nums[i] == 0) {
            return 100000;
        }

        int res = 100000;
        int end = min((int)nums.size(), i + nums[i] + 1);
        for (int j = i + 1; j < end; j++) {
            res = min(res, 1 + dfs(nums, j, memo));
        }
        memo[i] = res;
        return res;
    }
};