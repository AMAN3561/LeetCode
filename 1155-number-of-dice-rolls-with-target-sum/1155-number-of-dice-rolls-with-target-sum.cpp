class Solution {
public:
    long long int mod = 1e9+7;
    int solveUsingMEMO(int n, int k, int target, vector<vector<long long int>>& dp){
        if(n < 0 || target < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 && target != 0) return 0;
        if(n != 0 && target == 0) return 0;

        if(dp[n][target] != -1){
            return dp[n][target];
        }
        long long int ans = 0;
        for(int i = 1; i <= k; i++){
            ans = (ans%mod + solveUsingMEMO(n-1, k , target - i, dp)%mod)%mod;
            dp[n][target] = ans;
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
       int ans =  solveUsingMEMO(n, k, target, dp);
       return ans;
    }
};