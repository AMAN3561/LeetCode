class Solution {
public:
    int solve(int i, int n, vector<int>& costs, vector<int>& dp){
        int cost = INT_MAX;
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int j = i+1;
        if(j<=n){
            cost = costs[j-1] + (j-i)*(j-i) + solve(j, n, costs, dp);
        }
        j = i+2;
        if(j<=n){
            cost = min(cost, costs[j-1] + (j-i)*(j-i) + solve(j, n, costs, dp));
        }
        j = i+3;
        if(j<=n){
            cost = min(cost, costs[j-1] + (j-i)*(j-i) + solve(j, n, costs, dp));
        }
        dp[i] = cost;
        return dp[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        int i = 0;
        int ans = solve(i, n, costs, dp);
        return ans;
    }
};