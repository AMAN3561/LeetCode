class Solution {
public:
    int solveUsingRec(vector<int>& prices, int buy, int index){
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        if(buy){ // first portion is buykaro & second portion is skipbuy.
            profit = max((-prices[index] + solveUsingRec(prices, 0, index+1)), (0 + solveUsingRec(prices, 1, index+1)));
        }
        else{
            // first portion is sellkaro & second portion is skipsell.
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
    int solveusingTABULATION(vector<int>& prices, int buy, int index){
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for(int I = n-1; I >= 0; I--){
            for(int B = 0; B <= 1; B++){
                int profit = 0;
                if(B){
                    int buykaro = -prices[I] + dp[0][I+1];
                    int skipkaro = 0 + dp[1][I+1];
                    profit = max(buykaro, skipkaro);
                }
                else{
                    int sellkaro = +prices[I] + dp[1][I+1];
                    int skipkaro = 0+ dp[0][I+1];
                    profit = max(sellkaro, skipkaro);
                }
                dp[B][I] = profit;
            }
        }
        return dp[1][0];
    }
    int solveusingTABULATIONSO(vector<int>& prices, int buy, int index){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for(int I = n-1; I >= 0; I--){
            for(int B = 0; B <= 1; B++){
                int profit = 0;
                if(B){
                    int buykaro = -prices[I] + next[0];
                    int skipkaro = 0 + next[1];
                    profit = max(buykaro, skipkaro);
                }
                else{
                    int sellkaro = +prices[I] + next[1];
                    int skipkaro = 0+ next[0];
                    profit = max(sellkaro, skipkaro);
                }
                curr[B] = profit;
            }
            // shifting:
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int index = 0;
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        // int ans = solveUsingRec(prices, buy, index);
        // int ans = solveUsingMEMO(prices, buy, index, dp);
        // int ans = solveusingTABULATION(prices, buy, index);
        int ans = solveusingTABULATIONSO(prices, buy, index);
        return ans;
    }
};