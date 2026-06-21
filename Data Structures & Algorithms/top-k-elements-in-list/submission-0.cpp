class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> arr;
        for (int n: nums){
            arr[n]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for (const auto& a: arr){
            freq[a.second].push_back(a.first);
        }
        vector<int> result;
        for (int i = freq.size()-1; i>0; i--){
            for (int n: freq[i]){
            result.push_back(n);
            if (result.size() == k){
                return result;
                }
            }
        }
        return result;
    }
};
