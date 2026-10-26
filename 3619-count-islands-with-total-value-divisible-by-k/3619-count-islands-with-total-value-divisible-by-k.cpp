class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[newX][newY] && grid[newX][newY] != 0){
            return true;
        }
        else{
            return false;
        }
    }
    void bfscount_island(vector<vector<bool>>& visited, vector<vector<int>>& grid, int srcX, int srcY, long long& sum){
        queue<pair<int, int>> q;
        q.push({srcX, srcY});
        sum += grid[srcX][srcY];
        visited[srcX][srcY] = true;

        while(!q.empty()){
            auto front_pair = q.front();
            q.pop();
            int currX = front_pair.first;
            int currY = front_pair.second;
            
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int newX = dx[i] + currX;
                int newY = dy[i] + currY;
                if(isSafe(newX, newY, visited, grid)){
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                    sum += grid[newX][newY];
                }
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    long long sum = 0;
                    bfscount_island(visited, grid, i, j, sum);
                    if(sum%k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};