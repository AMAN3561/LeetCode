class Solution {
public:
    typedef tuple<int, int, int> p;
    int shortestPath(unordered_map<int, vector<pair<int, int>>>& adj, int src, int dst, int n, int k){
        vector<vector<int>> dist(k+2, vector<int>(n, INT_MAX));
        dist[0][src] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            auto [cost, node, flightUsed] = pq.top();
            pq.pop();
            if(cost > dist[flightUsed][node]){
                continue;
            }
            if(node == dst){
                return cost;
            }
            if(flightUsed == k+1){
                continue;
            }
            for(auto edge : adj[node]){
                auto nbr = edge.first;
                auto price = edge.second;

                int newCost = cost + price;
                if(newCost < dist[flightUsed + 1][nbr]){
                    dist[flightUsed+1][nbr] = newCost;
                    pq.push({newCost, nbr, flightUsed+1});
                }
            }
        }
        return -1;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].emplace_back(v, price);
        }
        int ans = shortestPath(adj, src, dst, n, k);
        return ans;
    }
};