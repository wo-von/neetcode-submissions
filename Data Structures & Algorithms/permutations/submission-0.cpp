class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {{}};
        vector<int> tmp(nums.begin()+1, nums.end());
        vector<vector<int>> perm = permute(tmp);
        vector<vector<int>> res;
        for (auto p: perm){
            for (int i = 0; i <= p.size(); i++){
                vector<int>copy = p;
                copy.insert(copy.begin() + i, nums[0]);
                res.push_back(copy);
            }
        }
        return res;
    }
};
