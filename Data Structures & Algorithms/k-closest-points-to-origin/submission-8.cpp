class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L = 0, R = (int)points.size() - 1;
        while (true) {
            int p = partitionIdx(L, R, points);
            if (p == k - 1) break;
            if (p < k - 1) L = p + 1;
            else           R = p - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:
    static int dist(const vector<int>& p) { return p[0]*p[0] + p[1]*p[1]; }

    int partitionIdx(int l, int r, vector<vector<int>>& pts) {
        int pivotDist = dist(pts[r]);      // snapshot before any swapping
        int i = l;
        for (int curr = l; curr < r; curr++) {
            if (dist(pts[curr]) <= pivotDist) {
                swap(pts[curr], pts[i]);
                i++;
            }
        }
        swap(pts[r], pts[i]);              // pts[i], not i
        return i;
    }
};