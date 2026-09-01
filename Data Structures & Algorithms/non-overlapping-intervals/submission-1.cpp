class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int start = 0, prevEnd = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); i++){
            int cstart = intervals[i][0], cend = intervals[i][1];
            if (cstart >= prevEnd){
                prevEnd = cend;
            } else {
                res++;
                prevEnd = min(prevEnd, cend);
            }
        }
        return res;
    }
};
