class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto vecG = [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), vecG);
        vector<vector<int>> result;
        for (int i = 0; i < (int)intervals.size(); i++) {
            if (result.empty() || intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};