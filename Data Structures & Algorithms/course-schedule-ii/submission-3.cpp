class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto p: prerequisites)
            graph[p[0]].push_back(p[1]);
        vector<int> path;
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, graph, visited, path))
                return {};
        return path;
    }

    bool dfs(int c, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path){
        if (visited[c] == 1) return false;   // gray: cycle
        if (visited[c] == 2) return true;    // black: done
        visited[c] = 1;
        for (auto g: graph[c])
            if (!dfs(g, graph, visited, path))
                return false;
        visited[c] = 2;
        path.push_back(c);                   // post-order, runs once per node
        return true;
    }
};
