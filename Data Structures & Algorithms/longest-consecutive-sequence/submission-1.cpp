class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> unums(nums.begin(), nums.end());
        int longest = 1;
        for (auto n: unums){
            int length = 1;
            auto curr = n;
            if (unums.contains(n-1)) continue;
            while (unums.contains(curr +1)){
                length++;
                curr++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
