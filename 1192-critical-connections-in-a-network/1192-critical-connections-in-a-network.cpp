class Solution {
public:
    void count_critical_connections(int parent, int src, int& time, unordered_map<int, bool>& visited, vector<int>& insertion_time, vector<int>& low_time, unordered_map<int, vector<int>>& adjList, vector<vector<int>>& ans){
        time++;
        visited[src] = true;
        insertion_time[src] = time;
        low_time[src] = time;

        for(auto nbr: adjList[src]){
            if(nbr == parent){
                continue;
            }
            else if(!visited[nbr]){
                count_critical_connections(src, nbr, time, visited, insertion_time, low_time, adjList, ans);
                low_time[src] = min(low_time[src], low_time[nbr]);
                if(low_time[nbr] > insertion_time[src]){
                    vector<int> temp;
                    // bridge found: 
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else{
                low_time[src] = min(low_time[src], low_time[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, const vector<vector<int>>& connections) {  
        vector<vector<int>> ans;
        int parent = -1;
        int src = 0; 
        int time = 0;
        unordered_map<int, bool> visited;
        vector<int> insertion_time(n);
        vector<int> low_time(n);

        unordered_map<int, vector<int>> adjList;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        count_critical_connections(parent, src, time, visited, insertion_time, low_time, adjList, ans);
        return ans;
    }
};