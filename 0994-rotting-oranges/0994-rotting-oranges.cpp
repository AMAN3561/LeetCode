class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<int>>& temp){
        if(newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> temp = grid;
        int min_time = 0;

        // find all rotten oranges and put them in queue.
        int m = temp.size();
        int n = temp[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(temp[i][j] == 2){
                    // every src node ko time 0 set kr diya :
                    q.push({{i, j}, 0});
                }
            }
        }
        // main logic :
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto front_node_pair = q.front();
            q.pop();
            auto front_node_coordinate = front_node_pair.first;
            int front_node_time = front_node_pair.second;
            
            int currX = front_node_coordinate.first;
            int currY = front_node_coordinate.second;

            for(int i = 0; i<4; i++){
                int newX = dx[i] + currX;
                int newY = dy[i] + currY;

                if(isSafe(newX, newY, temp)){
                    q.push({{newX, newY}, front_node_time + 1});
                    min_time = front_node_time + 1;
                    // mark this node as rotten :
                    temp[newX][newY] = 2;
                }
            }
        }

        // yaha taak kitne oranges rotten hone the ho gye hai.
        // aab check krna hai koi bacha toh nhi hai :
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(temp[i][j] == 1){
                    return -1;
                }
            }
        } 
        return min_time;
    }
};