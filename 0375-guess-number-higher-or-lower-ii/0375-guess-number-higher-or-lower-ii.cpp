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
    int solveUsingTABULATION(int start, int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int STRT = n; STRT>=start; STRT--){
            for(int N = STRT; N<=n; N++){
                if(STRT >= N) continue;
                int ans = INT_MAX;
                for(int i = STRT; i<=N; i++){
                    ans = min(ans, i + max(dp[STRT][i-1], dp[i+1][N]));
                } 
                dp[STRT][N] = ans;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingTABULATION(1, n);
        return ans;
    }
};