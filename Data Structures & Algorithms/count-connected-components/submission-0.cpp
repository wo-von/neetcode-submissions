class Solution {
private:
    vector<int> parent;
    // return the root of a union
    // merge paths
    int find (int a) {
        int root = a;
        while (parent[root] != root){        
            root = parent[root]; 
        }
        int next = a;
        while(parent[next] != root) {
            int tmp = parent[next];
            parent[next] = root;
            next = tmp;
        }
        return root;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int components = n;
        for (auto e: edges){
            int root1 = find(e[0]);
            int root2 = find(e[1]);
            if (root1 != root2){
                parent[root2] = root1;
                components--;
            } else {
                continue;
            }
        }
        return components;
    }
    
};
