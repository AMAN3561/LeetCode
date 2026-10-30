class Solution {
public:
    typedef tuple<int, int, int> t;
    int IdeChar(int n, string& labels, int k, unordered_map<int, vector<pair<int, int>>>& adj){
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        priority_queue<t, vector<t>, greater<t>> pq; // {weight, node, consecutiveCount}.
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while(!pq.empty()){
            auto [cost, node, consecutiveChar] = pq.top();
            pq.pop();

            if(cost > dist[node][consecutiveChar]){
                continue;
            }
            if(node == n-1){
                return cost;
            }
            for(auto edge: adj[node]){
                int nbr = edge.first;
                int price = edge.second;

                int newCount = (labels[nbr] == labels[node]) ? consecutiveChar+1 : 1;
                if(newCount > k){
                    continue;
                }
                if(dist[nbr][newCount] > cost + price){
                    dist[nbr][newCount] = cost + price;
                    pq.push({dist[nbr][newCount], nbr, newCount});
                }
            }
        }
        return -1;
    }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        int ans = IdeChar(n, labels, k, adj);
        return ans;
    }
};