class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1); // adj[parent] = {{child, time}, ...}
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> delays(n + 1, INT_MAX); // delay to get to this node
        dfs(adj, delays, k, 0);

        int answer = 0;
        for (int node = 1; node <= n; node++) {
            if (delays[node] == INT_MAX) {
                return -1;
            }
            answer = max(answer, delays[node]);
        }
        return answer;
    }

    void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& delays, int node, int delay) {
        if (delay >= delays[node]) {   // already reached this node at least as cheaply
            return;
        }
        delays[node] = delay;
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            dfs(adj, delays, neighbor, delay + weight);
        }
    }
};