class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> window;
        int max = nums[0];
        for (int i = 0; i < k; i++){
            window.push_back(nums[i]);
            if (nums[i] >= max)
                max = nums[i];
        }
        result.push_back(max);
        for (int i = k; i < nums.size(); i++){
            window.push_back(nums[i]); //add the new value to the stack
            int max_candidate = nums[i];
            for (int j = window.size() - 1; j > window.size() - k - 1; j-- ){
                if (max_candidate >= window[j]) continue;
                else max_candidate = window[j];
            }
            
            result.push_back(max_candidate);
        }
        return result;
    }
};
