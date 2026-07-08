class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int ns = newInterval[0], ne = newInterval[1];

        // start = first interval whose end >= ns (first one that could overlap)
        int l = 0, r = n;              // r = n => "belongs after the last interval"
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][1] >= ns) r = mid;
            else l = mid + 1;
        }
        int start = l;

        // end = last interval whose start <= ne
        // (find first interval starting after ne, step back one)
        l = 0; r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] > ne) r = mid;
            else l = mid + 1;
        }
        int end = l - 1;

        vector<vector<int>> res;
        for (int i = 0; i < start; i++) res.push_back(intervals[i]);

        if (start > end) {
            res.push_back(newInterval);                 // no overlap
        } else {
            int mergedStart = min(ns, intervals[start][0]);
            int mergedEnd   = max(ne, intervals[end][1]);
            res.push_back({mergedStart, mergedEnd});
        }

        for (int i = end + 1; i < n; i++) res.push_back(intervals[i]);
        return res;
    }
};