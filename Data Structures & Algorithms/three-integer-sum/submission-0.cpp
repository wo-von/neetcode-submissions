class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> seen;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); i++){
            int mid = -nums[i];
            int l = i + 1;
            int u = nums.size() - 1;
            while (l < u){
                if (nums[l] + nums[u] == mid){
                    tmp = {nums[i], nums[l], nums[u]};
                    seen.insert(tmp);
                    l++; u--;
                } else if (nums[l] + nums[u] < mid) l++;
                else u--;
            }
        }
        vector<vector<int>> result(seen.begin(), seen.end());
        return result;
    }
};