class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && visited[newX][newY] == false){
            return true;
        }
        else{
            return false;
        }
    }
    void bfstraversal(vector<vector<char>>& grid, vector<vector<bool>>& visited, int srcX, int srcY){
        queue<pair<int, int>> q;
        q.push({srcX, srcY});
        visited[srcX][srcY] = true;

        while(!q.empty()){
            auto top_pair = q.front();
            q.pop();
            int currX = top_pair.first;
            int currY = top_pair.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            
            for(int i = 0; i<4; i++){
                int newX = dx[i] + currX;
                int newY = dy[i] + currY;

                if(isSafe(newX, newY, grid, visited)){
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
            
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int no_of_islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfstraversal(grid, visited, i, j); 
                    no_of_islands++;   
                }
            } 
        }
        return no_of_islands;
    }
};