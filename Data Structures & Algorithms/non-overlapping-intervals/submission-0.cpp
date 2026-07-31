class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        return intervals.size() - dfs(intervals, -1, 0);
    }

    int dfs(vector<vector<int>>& intervals, int prev, int i){
        if (i == intervals.size()) return 0;
        int res = dfs(intervals, prev, i + 1);
        if (prev == -1 || intervals[prev][1]<=intervals[i][0]){
            return max(res, 1 + dfs(intervals, i, i + 1));
        }
        return res;
    }
};
