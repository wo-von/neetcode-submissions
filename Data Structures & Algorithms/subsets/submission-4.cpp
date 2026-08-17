class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>subset = {};
        backtrack(nums, res, subset, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, res, subset, i+1);
        subset.pop_back();
        backtrack(nums, res, subset, i+1);
    }
};
