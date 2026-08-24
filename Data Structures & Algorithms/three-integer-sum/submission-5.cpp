class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, 0, path, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, int start, int sum,
             vector<int>& path, vector<vector<int>>& res) {
        if ((int)path.size() == 3) {
            if (sum == 0) res.push_back(path);
            return;
        }
        for (int i = start; i < (int)nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;  // dedup at this level
            path.push_back(nums[i]);
            dfs(nums, i + 1, sum + nums[i], path, res);
            path.pop_back();                                     // un-choose mirrors choose
        }
    }
};