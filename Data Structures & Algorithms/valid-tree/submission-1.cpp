class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1){
            return false;
        }
        vector<vector<int>>adj(n);
        for (auto & e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        if (!dfs(adj, -1, 0, visited)){
            return false;
        }
        return (int)visited.size() == n;
    }
    bool dfs(vector<vector<int>>& adj, int parent, int node, 
        unordered_set<int>& visited){
        if (visited.count(node)){
            return false;
        }
        visited.insert(node);
        for (auto c: adj[node]){
            if (c == parent){
                continue;
            }
            if (!dfs(adj, node, c, visited)){
                return false;
            }
        }
        return true;
    }
};