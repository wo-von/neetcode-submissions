class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size(), 1);
        vector<int> suffixes(nums.size(), 1);
        prefixes.front() = 1;
        suffixes.back() = 1;
        for (size_t i = 1; i < nums.size(); i++){
            prefixes[i] *= prefixes[i-1]*nums[i-1];
        }
        for (int i = (int)nums.size() - 2; i >=0; i--){
            suffixes[i] *= suffixes[i+1]*nums[i+1];
        }
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++){
            result.push_back(prefixes[i]*suffixes[i]);
        }
        return result;

    }
};
