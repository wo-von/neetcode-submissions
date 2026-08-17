class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> dup_free;
    vector<int>state;
    backtrack(nums, dup_free, state, 0);
    vector<vector<int>> res(dup_free.begin(), dup_free.end());
    return res;        
    }
    void backtrack(vector<int>& nums, set<vector<int>>& df, vector<int>& state, int index) {
        if (index >= nums.size()) {
            df.insert(state);
            return;
        }
        state.push_back(nums[index]);
        backtrack(nums, df, state, index + 1);
        state.pop_back();
        backtrack(nums, df, state, index + 1);
    }
};
