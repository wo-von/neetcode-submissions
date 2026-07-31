using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0, high = points.size() - 1;
        while (true) {
            int p = partition(points, low, high);
            if (p == k - 1) break;
            else if (p < k - 1) low = p + 1;   // kth closest is to the right
            else high = p - 1;                 // kth closest is to the left
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int distSq(const vector<int>& v) {
        return v[0]*v[0] + v[1]*v[1];
    }

    // Lomuto partition; returns the pivot's final sorted index
    int partition(vector<vector<int>>& v, int lo, int hi) {
        int r = lo + rand() % (hi - lo + 1);   // random pivot → avoids O(n²)
        mySwap(v[r], v[hi]);

        int pivotDist = distSq(v[hi]);         // hoisted: pivot doesn't move in the loop
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (distSq(v[j]) < pivotDist) {
                mySwap(v[i], v[j]);
                i++;
            }
        }
        mySwap(v[i], v[hi]);
        return i;
    }
    template <typename T>
    void mySwap(T& a, T& b) {
        T tmp =std::move(a);
        a = std::move(b);
        b = std::move(tmp);
    }
};