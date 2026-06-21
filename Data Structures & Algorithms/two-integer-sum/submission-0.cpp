class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> A;
        for (int i=0;  i< nums.size(); i++) {
            int diff = target - nums[i];
            if (A.find(diff) != A.end()) {
                return {A[diff], i};
            }
            A.insert({nums[i], i});
        }
        return {};
    }
};
