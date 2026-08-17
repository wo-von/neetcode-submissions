class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, res, path, target, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res,
                   vector<int>& path, int target, int index) {
        if (target == 0) { res.push_back(path); return; }
        if (target < 0 || index >= (int)nums.size()) return;

        // take nums[index] — index stays, reuse allowed
        path.push_back(nums[index]);
        backtrack(nums, res, path, target - nums[index], index);
        path.pop_back();

        // skip nums[index]
        backtrack(nums, res, path, target, index + 1);
    }
};