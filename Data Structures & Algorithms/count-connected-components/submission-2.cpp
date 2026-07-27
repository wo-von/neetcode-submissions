class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, false);
        for (auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int components = 0;
        for (int node = 0; node < n; node++){
            if (visited[node])
                continue;
            stack<int> st;
            st.push(node);
            visited[node] = true;
            while(!st.empty()){
                auto n = st.top(); st.pop();
                for (auto neigh: adj[n]){
                    if (visited[neigh])
                        continue;
                    st.push(neigh);
                    visited[neigh] = true;
                }
            }
            components++;
        }
        return components;
    }
};
