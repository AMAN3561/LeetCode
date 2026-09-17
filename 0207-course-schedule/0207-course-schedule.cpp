class Solution {
public:
    void topological(int src, unordered_map<int, vector<int>>& adjList, unordered_map<int, int>& Indegree, vector<vector<int>>& prerequisites,queue<int>& q, vector<int>& topoOrder){
        for(int i = 0; i<src; i++){
            Indegree[src] = 0;
        }
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            Indegree[v]++;
        }
        for(int i = 0; i<src; i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front_Node = q.front();
            q.pop();
            topoOrder.push_back(front_Node);
            for(auto neighbour: adjList[front_Node]){
                Indegree[neighbour]--;
                if(Indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> topoOrder;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> Indegree;
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
        }
        topological(numCourses, adjList, Indegree, prerequisites, q, topoOrder);
        if(topoOrder.size() == numCourses){
            return true;
        }else{
            return false;
        }
    }
};
// class Solution {
// public: //solving by DFS :
//     bool dfshelper(int src, unordered_map<int, vector<int>>& adjList,
//                    unordered_map<int, bool>& dfstracker,
//                    unordered_map<int, bool>& visited) {
//         visited[src] = true;
//         dfstracker[src] = true;

//         for (auto neighbour : adjList[src]) {
//             if (!visited[neighbour]) {
//                 bool ans = dfshelper(neighbour, adjList, dfstracker, visited);
//                 if (ans == true) {
//                     return true;
//                 }
//             } else if (visited[neighbour] == true &&
//                        dfstracker[neighbour] == true) {
//                 return true;
//             }
//         }
//         dfstracker[src] = false; // backtracking.
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> adjList;
//         unordered_map<int, bool> dfstracker;
//         unordered_map<int, bool> visited;
//         for (auto it : prerequisites) {
//             int u = it[0];
//             int v = it[1];

//             adjList[u].push_back(v);
//         }
//         for (int src = 0; src < numCourses; src++) {
//             if (!visited[src]) {
//                 bool ans = dfshelper(src, adjList, dfstracker, visited);
//                 if (ans == true) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };