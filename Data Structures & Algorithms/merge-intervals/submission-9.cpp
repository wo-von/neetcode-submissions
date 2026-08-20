class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) {
                vector<int> new_interval = {merged.back()[0], max(intervals[i][1], merged.back()[1])};
                merged.back() = {new_interval[0], new_interval[1]};
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
