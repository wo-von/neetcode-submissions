using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int p = points.size() - 1;
        int low = 0;
        int high = points.size() - 1;
        // keep looping until pivot is at k
        while(true){
            p = QuickSelect(points, low, high);
            if (p == k - 1)
                break;
            else if (p < k - 1) // kth to the right
                low = p + 1;
            else
                high = p - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    int Dist(vector<int>& v){
        return v[0]*v[0] + v[1]*v[1];
    }
    // returns the index of the pivot
    int QuickSelect(vector<vector<int>>& v, int lo, int hi){
        if (lo >= hi)
            return lo;
        int pivot = hi;
        int pos = lo;
        int i = pos;
        for (int j = lo; j < hi; j++){
            if (Dist(v[j]) < Dist(v[pivot])){
                swap(v[i], v[j]);
                i++;
            }
        }
        swap(v[i], v[pivot]);
        return i;
    }
};
