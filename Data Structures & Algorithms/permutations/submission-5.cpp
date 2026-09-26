class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result = {};
        vector<bool>used(nums.size(), false);
        vector<int>path = {};
        backtrack(nums, result, used, path);
        return result;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& result,
        vector<bool>& used, vector<int>& path) {
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            }
            for (int i = 0; i < (int)nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, result, used, path);
                used[i] = false;
                path.pop_back();
            }
        }
};
