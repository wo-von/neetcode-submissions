class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();

        int windowMax = nums[0];
        for (int i = 1; i < k; i++)
            windowMax = std::max(windowMax, nums[i]);
        result.push_back(windowMax);

        for (int i = k; i < n; i++) {
            windowMax = nums[i];
            for (int j = i; j > i - k; j--)
                windowMax = std::max(windowMax, nums[j]);
            result.push_back(windowMax);
        }
        return result;
    }
};