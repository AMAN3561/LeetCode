class Solution {
public:
    int numSquareHelper(int n, vector<int>& dp){
        // base case :
        if(n == 0) return 0;
        if(n < 0) return 0;
        if(dp[n] != -1){
            return dp[n];
        }
        // 1 case hmm solve karenge :
        int i = 1;
        int ans = INT_MAX;
        int end = sqrt(n);
        while(i<= end){
            int perfect_square = i*i;
            int no_ofperfect_square = 1 + numSquareHelper(n - perfect_square, dp);
            if(no_ofperfect_square < ans){
                ans = no_ofperfect_square;
                dp[n] = ans;
            }
            i++;
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return numSquareHelper(n, dp);
    }
};