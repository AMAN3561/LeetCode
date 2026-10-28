class Solution {
public:
    long long int mod = 1e9+7;
    // int solveUsingMEMO(int n, int k, int target, vector<vector<long long int>>& dp){
    //     if(n < 0 || target < 0) return 0;
    //     if(n == 0 && target == 0) return 1;
    //     if(n == 0 && target != 0) return 0;
    //     if(n != 0 && target == 0) return 0;

    //     if(dp[n][target] != -1){
    //         return dp[n][target];
    //     }
    //     long long int ans = 0;
    //     for(int i = 1; i <= k; i++){
    //         ans = (ans%mod + solveUsingMEMO(n-1, k , target - i, dp)%mod)%mod;
    //         dp[n][target] = ans;
    //     }
    //     return ans;
    // }
    // int solveUsingTabulation(int n, int k, int target){
    //     vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0));
    //     dp[0][0] = 1;
    //     for(int a = 1; a<=n; a++){
    //         for(int t = 1; t<=target; t++){
    //             long long int ans = 0;
    //             for(int val = 1; val<=k; val++){
    //                 long long int temp = 0;
    //                 if(t-val >= 0){
    //                     temp = dp[a-1][t-val]%mod;
    //                 }
    //                 ans = (ans%mod + temp)%mod;
    //             }
    //             dp[a][t] = ans;
    //         }
    //     }
    //     return dp[n][target];
    // }
    int solveUsingSpaceOpt(int n, int k, int target){
        // vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0));
        vector<int> prev(target+1);
        vector<int> curr(target+1);

        prev[0] = 1;
        for(int a = 1; a<=n; a++){
            for(int t = 1; t<=target; t++){
                long long int ans = 0;
                for(int val = 1; val<=k; val++){
                    long long int temp = 0;
                    if(t-val >= 0){
                        temp = prev[t-val]%mod;
                    }
                    ans = (ans%mod + temp)%mod;
                }
                curr[t] = ans;
            }
            // shifting: 
            prev = curr;
        }
        return curr[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
        //    int ans =  solveUsingMEMO(n, k, target, dp);
        // int ans = solveUsingTabulation(n, k, target);
        int ans = solveUsingSpaceOpt(n, k, target);
        return ans;
    }
};