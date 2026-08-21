class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1); // adj[parent] = {{child, time}, ...}
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> delays(n + 1, INT_MAX);
        delays[k] = 0;

        // min-heap of {delay, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int delay = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (delay > delays[node]) {  // stale entry, already finalized cheaper
                continue;
            }
            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;
                int newDelay = delay + weight;
                if (newDelay < delays[neighbor]) {
                    delays[neighbor] = newDelay;
                    pq.push({newDelay, neighbor});
                }
            }
        }

        int answer = 0;
        for (int node = 1; node <= n; node++) {
            if (delays[node] == INT_MAX) return -1;
            answer = max(answer, delays[node]);
        }
        return answer;
    }
};