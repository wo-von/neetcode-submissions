class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool>memo;
        return dfs(nums, 0, memo);
    }
    bool dfs(vector<int>& nums, int index, unordered_map<int, bool>& memo){
        if (index == nums.size() - 1){
            return true;
        }
        if(nums[index] == 0) return false;
        if (memo.count(index)) return memo[index];
        int end = min((int)nums.size() - 1, index + nums[index]);
        for (int j = index + 1; j <= end; j++){
            if(dfs(nums, j, memo)) {
                memo[index] = true;
                return true;
            }
        }
        memo[index] = false;
        return false;
    }
};
