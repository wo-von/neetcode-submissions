class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1, lmax = 0, rmax = 0, water = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                lmax = max(lmax, h[l]);
                water += lmax - h[l];
                ++l;
            } else {
                rmax = max(rmax, h[r]);
                water += rmax - h[r];
                --r;
            }
        }
        return water;
    }
};
