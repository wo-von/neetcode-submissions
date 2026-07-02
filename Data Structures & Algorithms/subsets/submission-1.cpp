class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ss_size = 1 << nums.size();
        vector<vector<int>> result;
        result.reserve(ss_size);
        for (int num = 0; num < ss_size; num++) {
            vector<int> subset;
            int copy = num, i = 0;
            while (copy > 0) {
                if (copy & 1)
                    subset.push_back(nums[i]);
                copy >>= 1;
                i++;
            }
            result.push_back(std::move(subset));
        }
        return result;
    }
};