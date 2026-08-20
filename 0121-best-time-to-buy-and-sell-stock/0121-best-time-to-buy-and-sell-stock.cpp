class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int stock_buy = prices[0];
        for(int i = 1; i<prices.size(); i++){  
            if(stock_buy < prices[i]){
                max_profit = max(max_profit, abs(stock_buy - prices[i]));
            }
            else{
                stock_buy = prices[i];
            }
        }
        return max_profit;
    }
};