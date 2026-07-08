/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    int n = intervals.size();
    vector<int> starts(n), ends(n);
    for (int k = 0; k < n; k++) {
        starts[k] = intervals[k].start;
        ends[k]   = intervals[k].end;
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int rooms = 0;
    int endPtr = 0;
    for (int i = 0; i < n; i++) {
        if (starts[i] >= ends[endPtr]) {
            endPtr++;      // earliest meeting already ended → reuse its room
        } else {
            rooms++;       // nobody's free → allocate a new room
        }
    }
    return rooms;
}
};
