class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int gauge = intervals.front()[1];
        int start = intervals.front()[0];
        merged.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= gauge) {
                vector<int> new_interval = {start, max(intervals[i][1], gauge)};
                merged.pop_back();
                merged.push_back(new_interval);
                gauge = max(gauge, intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
                start = intervals[i][0];
                gauge = intervals[i][1];
            }
        }
        return merged;
    }
};
