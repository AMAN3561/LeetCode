class Solution {
public:
    int solveUsingRec(int n){
        // base case :
        if(n == 1 || n==2){
            return n;
        }
        // 1  step stairs :
        int steps = solveUsingRec(n-1) + solveUsingRec(n-2);
        return steps;
    }
    int solveUsingMEMO(int n, vector<int>& dp){
        // base case :
        if(n == 1 || n==2){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        // 1  step stairs :
        int steps = solveUsingMEMO(n-1, dp) + solveUsingMEMO(n-2, dp);
        dp[n] = steps;
        return dp[n];
    }
    int solveUsingTABULATION(int n){
        // base case :
        if(n <= 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int N = 3; N<=n; N++){
            dp[N] = dp[N-1] + dp[N-2];
        }
        return dp[n];
    }
    int solveUsingTABULATIONSO(int n){
        if(n <= 2) return n;
        int nbr1 = 2;
        int nbr2 = 1;
        for(int N = 3; N<=n; N++){
            int curr = nbr1 + nbr2;

            // shifting :
            nbr2 = nbr1;
            nbr1 = curr;
        }
        return nbr1;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // int ans = solveUsingRec(n);
        // int ans = solveUsingMEMO(n, dp);
        // int ans = solveUsingTABULATION(n);
        int ans = solveUsingTABULATIONSO(n);
        return ans;
    }
};