class Solution {
public:
    int Left = 0;
    int Up = 1;
    static constexpr int MOD = 1000000007;
    int usingRec(vector<vector<int>>& grid, int i, int j, int camefrom, int m, int n, vector<vector<vector<int>>>& dp){
        // base case :
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j][camefrom] != -1){
            return dp[i][j][camefrom];
        }
        if(grid[i][j] == 1){
            if(camefrom == Left){
                return dp[i][j][camefrom] = usingRec(grid, i+1, j, Up, m, n, dp);
            }
            else{
                return dp[i][j][camefrom] = usingRec(grid, i, j+1, Left, m, n, dp);
            }
        }
        int total = 0;
        total = (total + usingRec(grid, i, j+1, Left, m, n, dp))%MOD;
        total = (total + usingRec(grid, i+1, j, Up, m, n, dp))%MOD;
        dp[i][j][camefrom] = total;
        return total;
    }
    int usingMEMO(vector<vector<int>>& grid, int i, int j, int camefrom, int m, int n, vector<vector<vector<int>>>& dp){
        // base case :
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j][camefrom] != -1){
            return dp[i][j][camefrom];
        }
        if(grid[i][j] == 1){
            if(camefrom == Left){
                return dp[i][j][camefrom] = usingRec(grid, i+1, j, Up, m, n, dp);
            }
            else{
                return dp[i][j][camefrom] = usingRec(grid, i, j+1, Left, m, n, dp);
            }
        }
        int total = 0;
        total = (total + usingRec(grid, i, j+1, Left, m, n, dp))%MOD;
        total = (total + usingRec(grid, i+1, j, Up, m, n, dp))%MOD;
        dp[i][j][camefrom] = total;
        return total;
    }
    int uniquePaths(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        int ans = usingMEMO(grid, i, j, Left, m, n, dp);
        return ans;
    }
};