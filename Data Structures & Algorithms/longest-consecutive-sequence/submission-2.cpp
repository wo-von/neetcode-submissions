class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> mp;
        int longest = 1;
        for (auto num: nums){
            if (!mp[num]){
                mp[num] = mp[num-1] + mp[num+1]+1;
                mp[num-mp[num-1]] = mp[num];
                mp[num+mp[num+1]] = mp[num];
            }
            longest = max (longest, mp[num]);
        }
        return longest;
    }
};
