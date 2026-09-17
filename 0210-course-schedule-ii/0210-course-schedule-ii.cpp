class Solution {
public:
    void toplogical_Sort(int src, unordered_map<int, vector<int>>& adjList, queue<int>& q, unordered_map<int, int>& Indegree, vector<int>& topoOrder, vector<vector<int>>& prerequisites){
        for(int i = 0; i<src; i++){
            Indegree[i] = 0;
        }
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];

            Indegree[u]++;
        }
        for(int i = 0; i<src; i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front_node = q.front();
            q.pop();
            topoOrder.push_back(front_node);
            for(auto neighbour: adjList[front_node]){
                Indegree[neighbour]--;
                if(Indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> Indegree;
        vector<int> topoOrder;

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adjList[v].push_back(u);
        }
        toplogical_Sort(numCourses, adjList, q, Indegree, topoOrder, prerequisites);
        if(topoOrder.size() != numCourses){
            return {};
        }
        return topoOrder;
    }
};