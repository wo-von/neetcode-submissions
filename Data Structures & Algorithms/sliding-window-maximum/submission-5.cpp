class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        priority_queue<pair<int, int>> window;   // (value, index); ties break on index — fine
        int n = nums.size();
        for (int i = 0; i < k; i++)
            window.push({nums[i], i});
        vector<int> result;
        result.push_back(window.top().first);
        for (int i = k; i < n; i++) {
            while (!window.empty() && window.top().second < i - k + 1)
                window.pop();
            window.push({nums[i], i});
            result.push_back(window.top().first);
        }
        return result;

    }
};
