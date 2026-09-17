class Solution {
public:
    bool dfshelper(int src, unordered_map<int, vector<int>>& adjList,
                   unordered_map<int, bool>& dfstracker,
                   unordered_map<int, bool>& visited) {
        visited[src] = true;
        dfstracker[src] = true;

        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                bool ans = dfshelper(neighbour, adjList, dfstracker, visited);
                if (ans == true) {
                    return true;
                }
            } else if (visited[neighbour] == true &&
                       dfstracker[neighbour] == true) {
                return true;
            }
        }
        dfstracker[src] = false; // backtracking.
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, bool> dfstracker;
        unordered_map<int, bool> visited;
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
        }
        for (int src = 0; src < numCourses; src++) {
            if (!visited[src]) {
                bool ans = dfshelper(src, adjList, dfstracker, visited);
                if (ans == true) {
                    return false;
                }
            }
        }
        return true;
    }
};