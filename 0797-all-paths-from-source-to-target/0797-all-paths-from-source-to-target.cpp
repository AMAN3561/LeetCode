class Solution {
public:
    void dfs(vector<int>& temp, vector<vector<int>>& paths, int src, int dest, vector<vector<int>>& graph){
        temp.push_back(src);
        if(src == dest){
            paths.push_back(temp);
            return;
        }
        for(auto nbr: graph[src]){
            dfs(temp, paths, nbr, dest, graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> paths;
        int src = 0;
        int dest = graph.size() -1;
        dfs(temp, paths, src, dest, graph);
        return paths;
    }
};