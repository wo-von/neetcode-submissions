class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distSq = [](const vector<int>& p) {
            return p[0]*p[0] + p[1]*p[1];        // squared distance, ordering-preserving
        };

        // max-heap: farthest point sits on top
        priority_queue<pair<int, int>> heap;      // {distSq, index}
        for (int i = 0; i < (int)points.size(); i++) {
            heap.push({distSq(points[i]), i});
            if ((int)heap.size() > k)
                heap.pop();                       // drop the farthest, keep K closest
        }

        vector<vector<int>> res;
        res.reserve(k);
        while (!heap.empty()) {
            res.push_back(points[heap.top().second]);   // map index back to the point
            heap.pop();
        }
        return res;
    }
};