class Solution {
public:
    int solveUsingRec(vector<int>& prices, int buy, int index){
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        if(buy){
            profit = max((-prices[index] + solveUsingRec(prices, 0, index+1)), (0 + solveUsingRec(prices, 1, index+1)));
        }
        else{
            profit = max((+prices[index] + solveUsingRec(prices, 1, index+1)), (0+ solveUsingRec(prices, 0, index+1)));
        }
        return profit;
    }
    int solveUsingMEMO(vector<int>& prices, int buy, int index, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[buy][index] != -1){
            return dp[buy][index];
        }
        int profit = 0;
        if(buy){
            profit = max((-prices[index] + solveUsingMEMO(prices, 0, index+1, dp)), (0 + solveUsingMEMO(prices, 1, index+1, dp)));
        }
        else{
            profit = max((+prices[index] + solveUsingMEMO(prices, 1, index+1, dp)), (0+ solveUsingMEMO(prices, 0, index+1, dp)));
        }
        dp[buy][index] = profit;
        return dp[buy][index];
    }
    // int solveUsingTABULATION(vector<int>& prices, int buy, int index, ){
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1))
    //     dp[n] = 0;

    //     int profit = 0;
    //     if(buy){
    //         profit = max((-prices[index] + solveUsingMEMO(prices, 0, index+1, dp)), (0 + solveUsingMEMO(prices, 1, index+1, dp)));
    //     }
    //     else{
    //         profit = max((+prices[index] + solveUsingMEMO(prices, 1, index+1, dp)), (0+ solveUsingMEMO(prices, 0, index+1,)));
    //     }
    //     dp[buy][index] = profit;
    //     return dp[buy][index];
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int index = 0;
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        // int ans = solveUsingRec(prices, buy, index);
        int ans = solveUsingMEMO(prices, buy, index, dp);
        return ans;
    }
};