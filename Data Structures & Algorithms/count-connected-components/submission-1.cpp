class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;
        for (auto neigh: adj[node]){
            if (!visited[neigh])
                dfs(adj, visited, neigh);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, false);
        // build the adjacency matrix
        for (auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int components = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                dfs(adj, visited, i);
                components++;
            }
        }
        return components;
    }
};
