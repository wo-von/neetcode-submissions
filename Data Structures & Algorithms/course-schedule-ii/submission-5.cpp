class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // [a, b] means "b before a", so the edge points b -> a
        for (auto& p : pre) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;                 // one more thing blocking `course`
        }

        // the pool: everything with nothing blocking it
        queue<int> ready;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ready.push(i);
            }
        }

        vector<int> order;
        while (!ready.empty()) {
            int u = ready.front();
            ready.pop();
            order.push_back(u);                 // emit it

            for (int v : adj[u]) {              // "remove" u from the graph
                indegree[v]--;
                if (indegree[v] == 0) {         // v just became unblocked
                    ready.push(v);
                }
            }
        }

        if (order.size() < n) {                 // some nodes never unblocked
            return {};
        }
        return order;
    }
};