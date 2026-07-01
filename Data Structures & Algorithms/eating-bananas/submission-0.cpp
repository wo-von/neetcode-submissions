class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_pile = 0;
        for (auto pile : piles) {
            if (pile > max_pile) max_pile = pile;
        }
        int l = 1, r = max_pile;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long time = 0;
            for (int i = 0; i < n; i++) {
                time += (piles[i] + mid - 1) / mid;
            }
            if (time > h) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};