class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> keys;
    for (std::size_t i = 0; i < nums.size(); i ++){
        if (keys.contains(nums[i])) return true;
        keys.insert(nums[i]);   
    }
    return false;
    }
};