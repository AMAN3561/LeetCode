// class Solution {
// public:
//     void bfstraversal(vector<vector<int>>& isConnected, int src,unordered_map<int, bool>& visited, int n){
//         queue<int> q;
//         q.push(src);
//         visited[src] = true;
//         while(!q.empty()){
//             int front = q.front();
//             q.pop();
//             for(int nbrIdx = 0; nbrIdx<n; nbrIdx++){
//                 int nbr = nbrIdx;
//                 if(isConnected[front][nbrIdx] == 1){
//                     if(!visited[nbrIdx]){
//                         q.push(nbrIdx);
//                         visited[nbrIdx] = true;
//                     }
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int count = 0;
//         unordered_map<int, bool>visited;
//         for(int i = 0; i<n; i++){
//             if(!visited[i]){
//                 bfstraversal(isConnected, i, visited, n);
//                 count++;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    void bfstraversal(vector<vector<int>>& isConnected, int src,unordered_map<int, bool>& visited, int n){
        visited[src] = true;
        int row = src; 
        int col = n;

        for(int nbrIdx = 0; nbrIdx<n; nbrIdx++){
            int nbr = nbrIdx;
            if(isConnected[row][nbrIdx]){
                if(!visited[nbr]){
                    bfstraversal(isConnected, nbr, visited, n);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        unordered_map<int, bool>visited;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                bfstraversal(isConnected, i, visited, n);
                count++;
            }
        }
        return count;
    }
};