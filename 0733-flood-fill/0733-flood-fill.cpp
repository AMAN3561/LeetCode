class Solution {
public: 
    bool isSafe(int new_x, int new_y, vector<vector<bool>>& visited, int old_color, vector<vector<int>>& ans){
        if(new_x >= 0 && new_y >= 0 && new_x < ans.size() && new_y < ans[0].size() && ans[new_x][new_y] == old_color && !visited[new_x][new_y]){
            return true;
        }
        else{
            return false;
        }
    }
    void dfstraversal(vector<vector<int>>& image, vector<vector<int>>& ans, vector<vector<bool>>& visited, int old_color, int new_color, int sr, int sc){
        visited[sr][sc] = true;
        ans[sr][sc] = new_color;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i<4; i++){
            int new_x = dx[i] + sr;
            int new_y = dy[i] + sc;
            if(isSafe(new_x, new_y, visited, old_color, ans)){
                dfstraversal(image, ans, visited, old_color, new_color, new_x, new_y);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int old_color = image[sr][sc];
        int new_color = color;
        // dfs traversal :
        dfstraversal(image, ans, visited, old_color, new_color, sr, sc);
        return ans;
    }
};