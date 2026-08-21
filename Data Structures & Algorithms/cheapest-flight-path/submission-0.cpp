class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            int from = f[0];
            int to   = f[1];
            int cost = f[2];
            adj[from].push_back({cost, to});
        }

        // {cost_so_far, node, level}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, -1});

        vector<int> best_level(n, INT_MAX);

        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int this_cost  = top[0];
            int this_node  = top[1];
            int this_level = top[2];

            if (this_node == dst) {
                return this_cost;
            }
            if (this_level >= k) {
                continue;
            }
            if (this_level >= best_level[this_node]) {
                continue;
            }
            best_level[this_node] = this_level;

            for (auto& neigh : adj[this_node]) {
                int next_cost = this_cost + neigh.first;
                int next_node = neigh.second;
                pq.push({next_cost, next_node, this_level + 1});
            }
        }
        return -1;
    }
};