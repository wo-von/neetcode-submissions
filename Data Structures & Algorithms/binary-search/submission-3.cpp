class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target){ // we might have a member smaller than the target
                                                // but the target might still be missing
            return it - nums.begin();
        } else return -1;
    }
};
