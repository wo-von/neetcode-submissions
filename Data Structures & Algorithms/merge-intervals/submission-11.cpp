// by claude
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        size_t last = 0;                                  // index of the interval being built
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[last][1]) {  // overlap → extend right edge
                intervals[last][1] = max(intervals[last][1], intervals[i][1]);
            } else {                                      // gap → start a new one
                ++last;
                if (last != i) intervals[last] = std::move(intervals[i]);
            }
        }
        intervals.resize(last + 1);
        return std::move(intervals);
    }
};