class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;                  // ordered: begin() is the smallest card
        for (int c : hand) count[c]++;

        while (!count.empty()) {
            int start = count.begin()->first; // anchor = smallest remaining
            for (int v = start; v < start + groupSize; v++) {
                auto it = count.find(v);
                if (it == count.end()) return false;
                if (--it->second == 0) count.erase(it);
            }
        }
        return true;
    }
};