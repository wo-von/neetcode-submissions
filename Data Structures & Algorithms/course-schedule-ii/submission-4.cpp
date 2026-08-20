class Solution {
    vector<vector<int>> adj;
    vector<int> state;      // 0 = unseen, 1 = on current path, 2 = done
    vector<int> order;
    bool cycle = false;

    void dfs(int u) {
        state[u] = 1;                                   // grey: entering
        for (int v : adj[u]) {
            if (state[v] == 1) { cycle = true; return; } // back edge
            if (state[v] == 0) { dfs(v); if (cycle) return; }
            // state[v] == 2 → already done, fall through to next v
        }
        state[u] = 2;                                   // black: leaving
        order.push_back(u);                             // post-order
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        adj.assign(n, {});
        state.assign(n, 0);
        for (auto& p : pre) adj[p[1]].push_back(p[0]);   // p[1] before p[0]

        for (int i = 0; i < n; i++)
            if (state[i] == 0) { dfs(i); if (cycle) return {}; }

        reverse(order.begin(), order.end());
        return order;
    }
};