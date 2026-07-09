class Solution {
public:
    int rob(vector<int>& nums) {
        int prevBest = 0; // best using houses [0..i-2]
        int currBest = 0; // best using houses [0..i-1]
        for (int i = 0; i < (int)nums.size(); i++) {
            int robHere = prevBest + nums[i];
            int skipHere = currBest;
            int best = std::max(robHere, skipHere);
            prevBest = currBest;
            currBest = best;
        }
        return currBest;
    }
};
