class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].emplace_back(v, wt);
        }
        pq.push({0, k});

        int visitedNodecount = 0;
        unordered_map<int, bool> visited;
        int timeans = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int currtime = top.first;
            int currnode = top.second;

            if(visited[currnode] == true){
                continue;
            }
            visited[currnode] = true;
            visitedNodecount++;
            timeans = max(timeans, currtime);

            for(auto j: adj[currnode]){
                int nbrnode = j.first;
                if(visited[nbrnode] == false){
                    int edge_ke_upparkatime = j.second;
                    pq.push({currtime + edge_ke_upparkatime, nbrnode});
                }
            }
        }
        if(visitedNodecount == n){
            return timeans;
        }
        else{
            return -1;
        }
    }
};