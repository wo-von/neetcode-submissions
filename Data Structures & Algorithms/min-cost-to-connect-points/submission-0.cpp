class UnionFind {
    vector<int> parent, rank_;
public:
    UnionFind(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);   // path compression
        return parent[x];
    }

    bool unite(int a, int b) {             // now returns "did a merge happen?"
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;        // already connected
        if (rank_[ra] < rank_[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb]) rank_[ra]++;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf(n);

        vector<array<int, 3>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());

        int res = 0;
        for (auto& [dist, u, v] : edges)
            if (uf.unite(u, v))
                res += dist;
        return res;
    }
};