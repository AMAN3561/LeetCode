class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i,int j, int row, int col, int& maxi){
        // base case:
        if(i>=row || j>= col) return 0;

        // explore all 3 cases :
        int right= solve(matrix,i,j+1,row,col,maxi);
        int diagonal= solve(matrix,i+1,j+1,row,col,maxi);
        int down= solve(matrix,i+1,j,row,col,maxi);

        // check can we build square from current position
        if(matrix[i][j]=='1'){
            int ans= 1+ min(right,min(diagonal,down));
            // yeh imp h.
            maxi= max(maxi,ans);
            return ans;
        }
        else{
            // agar 0 pr hi khade ho toh answer bhi zero hoga.
            return 0;
        }
    }
    int solveUsingMEMO(vector<vector<char>>& matrix, int i,int j, int row, int col, int& maxi, vector<vector<int>>& dp){
        // base case:
        if(i>=row || j>= col) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // explore all 3 cases :
        int right= solveUsingMEMO(matrix,i,j+1,row,col,maxi, dp);
        int diagonal= solveUsingMEMO(matrix,i+1,j+1,row,col,maxi, dp);
        int down= solveUsingMEMO(matrix,i+1,j,row,col,maxi, dp);

        // check can we build square from current position
        if(matrix[i][j]=='1'){
            int ans= 1+ min(right,min(diagonal,down));
            // yeh imp h.
            dp[i][j] = ans;
            maxi = max(maxi,ans);
            return dp[i][j];
        }
        else{
            dp[i][j] = 0;
            return dp[i][j];
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i=0;
        int j=0;
        int row= matrix.size();
        int col= matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        // int ans = solve(matrix,i,j,row,col,maxi);
        int ans = solveUsingMEMO(matrix,i,j,row,col,maxi, dp);
        return maxi*maxi;
    }
};