class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        std::greater<pair<int, int>>>pq;
        for (auto& t: times) {
            int parent = t[0];
            int child = t[1];
            int delay = t[2];
            adj[parent].push_back({child, delay});
        }
        vector<int> delays(n + 1, INT_MAX);
        delays[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int delay = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (delay > delays[node]){
                continue;
            }
            for (auto& nodes: adj[node]){
                int neigh = nodes.first;
                int neigh_delay = nodes.second;
                int new_delay = delay + neigh_delay;
                if (new_delay < delays[neigh]){
                    delays[neigh] = new_delay;
                    pq.push({new_delay, neigh});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <=n; i++){
            if(delays[i] == INT_MAX){
                return -1;
            }
            res = std::max(res, delays[i]);
        }
        return res;
    }
};
