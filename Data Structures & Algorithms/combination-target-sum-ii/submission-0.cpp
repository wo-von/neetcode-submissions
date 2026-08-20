class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        backtrack(candidates, res, path, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, vector<vector<int>>& res,
        vector<int>& path, int target, int index) {

        // (1) check on ARRIVAL, and before the bounds guard
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (index >= (int)candidates.size() || target < 0) {
            return;
        }

        // take the number
        path.push_back(candidates[index]);
        backtrack(candidates, res, path, target - candidates[index], index + 1);
        path.pop_back();

        // (3) don't take it -> skip every copy of this value
        int next = index;
        while (next < (int)candidates.size() && candidates[next] == candidates[index]) {
            next++;
        }
        backtrack(candidates, res, path, target, next);
    }
};
