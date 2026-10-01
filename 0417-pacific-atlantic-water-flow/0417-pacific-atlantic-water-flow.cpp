class Solution {
public: 
    void dfs(int row, int col, vector<vector<bool>>& ocean_visited, vector<vector<int>>& heights){
        int totalrows = heights.size();
        int totalcols = heights[0].size();
        
        ocean_visited[row][col] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i<4; i++){
            int newX = dx[i] + row;
            int newY = dy[i] + col;

            if(newX >= 0 && newY >= 0 && newX < totalrows && newY < totalcols && ocean_visited[newX][newY] == false && heights[row][col] <= heights[newX][newY]){
                dfs(newX, newY, ocean_visited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int totalrows = heights.size();
        int totalcols = heights[0].size();

        vector<vector<bool>> pacific_visited(totalrows, vector<bool>(totalcols, false));
        vector<vector<bool>> atlantic_visited(totalrows, vector<bool>(totalcols, false));

        for(int col = 0; col< totalcols; col++){
            dfs(0, col, pacific_visited, heights);
            dfs(totalrows - 1, col, atlantic_visited, heights);
        }
        for(int row = 0; row< totalrows; row++){
            dfs(row, 0, pacific_visited, heights);
            dfs(row, totalcols - 1, atlantic_visited, heights);
        }

        vector<vector<int>> ans;
        for(int i = 0; i<totalrows; i++){
            for(int j = 0; j<totalcols; j++){
                if(pacific_visited[i][j] == 1 && atlantic_visited[i][j] ==1){
                    ans.push_back({i, j});
                } 
            }
        }
        return ans;
    }
};