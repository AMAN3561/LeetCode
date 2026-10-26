class Solution {
public:
    void dfsTraversal(vector<bool>& visited, vector<vector<pair<int, int>>>& adj, int& ans, int u){
        visited[u] = true;
        for(auto [nbr, dir]: adj[u]){
            if(visited[nbr]) continue;
            if(dir == 1){
                ans++;
            }
            dfsTraversal(visited, adj, ans, nbr);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n, 0);
        int ans = 0;

        for(auto e: connections){
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        dfsTraversal(visited, adj, ans, 0);
        return ans;
    }
};