class Solution {
public:
    int solveUsingRec(int start, int n){
        // base case :
        if(start >= n){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = start; i<=n; i++){
            ans = min(ans, i + max(solveUsingRec(start, i-1), solveUsingRec(i+1, n)));
        }
        return ans;
    }
    int solveUsingMEMO(int start, int n, vector<vector<int>>& dp){
        // base case :
        if(start >= n){
            return 0;
        }
        if(dp[start][n] != -1){
            return dp[start][n];
        }
        int ans = INT_MAX;
        for(int i = start; i<=n; i++){
           ans = min(ans, i + max(solveUsingMEMO(start, i-1, dp), solveUsingMEMO(i+1, n, dp)));
        }
        dp[start][n] = ans;
        return dp[start][n];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMEMO(1, n, dp);
        return ans;
    }
};