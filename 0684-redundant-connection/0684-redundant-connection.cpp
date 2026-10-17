class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x], parent); // path compression.
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n, 0);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            // find :
            int a = find(u, parent);
            int b = find(v, parent);

            // union :
            if(a == b){
                return {u, v};
            }
            if(rank[a] == rank[b]){
                parent[b] = a;
                rank[a]++;
            }
            else if(rank[a] > rank[b]){
                parent[b] = a;
            }
            else{
                parent[a] = b;
            }
        }
        return {-1, -1};
    }
};