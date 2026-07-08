class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int req = prerequisites[i][1];
            graph[req].push_back(course);
        }
        for (int i = 0; i < numCourses; i++){
            if(!dfs(i, visited, graph))
                return false;
        }
        return true;
    }
    // returns false if there is a loop
    bool dfs(int c, vector<int>& visited, vector<vector<int>>& graph) {
        if (visited[c] == 1)
            return false;
        if (visited[c] == 2)
            return true;
        visited[c] = 1;
        for (auto p: graph[c]){
             if(!dfs(p, visited, graph))
                return false;
        }
        visited[c] = 2;
        return true;
    }
};
