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
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // int ans = solveUsingRec(n);
        int ans = solveUsingMEMO(n, dp);
        return ans;
    }
};