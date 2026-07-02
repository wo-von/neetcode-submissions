class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ss_size = pow(2, nums.size());
        vector<vector<int>> result;
        result.push_back({});
        for (int num = 1; num < ss_size; num++){
            vector<int> subset;
            int copy = num, i = 0;
            while (copy > 0){
                if (copy & 1)
                    subset.push_back(nums[i]);
                copy = copy >> 1;
                i++;
            }
            result.push_back(subset);
        }
        return result;
    }
};
