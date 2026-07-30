class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int n = nums[i];
            int a = curMax * n, b = curMin * n;
            curMax = max({n, a, b});
            curMin = min({n, a, b});
            best = max(best, curMax);
        }
        return best;
    }
};