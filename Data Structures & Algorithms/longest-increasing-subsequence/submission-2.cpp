class Solution {
public:
    // memo[current][lastTaken + 1] caches the answer for a (current, lastTaken) pair.
    // The "+ 1" only exists to turn lastTaken = -1 into a valid index 0.
    vector<vector<int>> memo;

    // Returns the longest increasing subsequence we can still build,
    // looking at nums[current..end], given that the previous element
    // we committed to is nums[lastTaken] (lastTaken = -1 means none yet).
    int bestLengthFrom(int current, int lastTaken, vector<int>& nums) {
        // Ran off the end: nothing left to add.
        if (current == nums.size()) {
            return 0;
        }

        // Already solved this exact situation before.
        if (memo[current][lastTaken + 1] != -1) {
            return memo[current][lastTaken + 1];
        }

        // Option 1: SKIP nums[current]. Move on, ceiling unchanged.
        int skip = bestLengthFrom(current + 1, lastTaken, nums);

        // Option 2: TAKE nums[current], but only if allowed —
        // nothing taken yet, or it's strictly bigger than the last taken.
        int take = 0;
        bool allowed = (lastTaken == -1) || (nums[lastTaken] < nums[current]);
        if (allowed) {
            take = 1 + bestLengthFrom(current + 1, current, nums);
        }

        int best = max(skip, take);
        memo[current][lastTaken + 1] = best;
        return best;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return bestLengthFrom(0, -1, nums);
    }
};