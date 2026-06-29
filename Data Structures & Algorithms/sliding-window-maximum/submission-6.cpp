class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deck;
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while(!deck.empty() && nums[deck.back()] < nums[i])
                deck.pop_back();
            deck.push_back(i);
            while(!deck.empty() && deck.front() <= i - k)
                deck.pop_front();
            if (i >= k - 1)
                result.push_back(nums[deck.front()]);
        }
        return result;
    }
};
