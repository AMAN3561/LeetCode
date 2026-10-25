class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0 && visited[newX][newY] == false){
            return true;
        }
        else{
            return false;
        }
    }
    bool bfsTraversal(vector<vector<bool>>& visited, vector<vector<int>>& grid, int srcX, int srcY){
        queue<pair<int, int>> q;
        bool isClosed = true;
        q.push({srcX, srcY});
        visited[srcX][srcY] = true;

        while(!q.empty()){
            auto front_pair = q.front();
            q.pop();

            int currX = front_pair.first;
            int currY = front_pair.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i<4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(newX<0 || newX>=grid.size() ||newY<0 || newY>=grid[0].size()){
                    isClosed=false;
                    continue;
                }
                if(isSafe(newX, newY, grid, visited)){
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int no_of_closed_island = 0;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 0 && i != 0 && i!= n-1 && j != 0 && j != m-1){
                    if(!bfsTraversal(visited, grid, i, j)){
                        continue;
                    }
                    else{
                        no_of_closed_island++;
                    } 
                }
            }
        }
        return no_of_closed_island;
    }
};