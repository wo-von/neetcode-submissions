class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); //pair of {neigh, delay} for nodes
        for (auto& t: times) {
            int node = t[0];
            int neigh = t[1];
            int delay = t[2];
            adj[node].push_back({neigh, delay});
        }
        vector<int> delays(n + 1, INT_MAX);
        dfs(adj, k, delays, 0);
        int answer = 0;
        for (size_t i = 1; i <= n; i++){
            if (delays[i] == INT_MAX) {
                return -1;
            }
            answer = max(answer, delays[i]);
        }
        return answer;
        
    }
    void dfs(vector<vector<pair<int, int>>>& adj, int node, vector<int>& delays, int delay) {
        if (delay >= delays[node]) {
            return;
        }
        delays[node] = delay;
        for (auto& neigh: adj[node]){
            int neighbor = neigh.first;
            int delay_neighbor = neigh.second;
            int new_delay = delay_neighbor + delay;
            dfs(adj, neighbor, delays, new_delay);
        }
    }
};
