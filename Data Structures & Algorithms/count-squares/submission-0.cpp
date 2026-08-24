class CountSquares {
private:
    unordered_map<int, unordered_map<int, int>> byX;   // x -> y -> multiplicity

    int cnt(int x, int y) const {
        auto itx = byX.find(x);
        if (itx == byX.end()) return 0;
        auto ity = itx->second.find(y);
        if (ity == itx->second.end()) return 0;
        return ity->second;
    }

public:
    CountSquares() {}

    void add(vector<int> point) {
        byX[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        auto itx = byX.find(px);
        if (itx == byX.end()) return 0;

        int total = 0;
        for (auto& [y, c] : itx->second) {     // points sharing the query's column
            int side = abs(y - py);
            if (side == 0) continue;           // zero area
            total += c * cnt(px - side, py) * cnt(px - side, y);
            total += c * cnt(px + side, py) * cnt(px + side, y);
        }
        return total;
    }
};