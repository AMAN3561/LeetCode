class Solution {
public:
    int solveUsingRec(string& text1, string& text2, int first, int second){
        // base case: 
        if(first == text1.length()) return 0;
        if(second == text2.length()) return 0;

        int ans = 0;
        if(text1[first] == text2[second]){
            ans = 1 + solveUsingRec(text1, text2, first+1, second+1);
        }
        else{
            ans = 0 + max(solveUsingRec(text1, text2, first, second+1), solveUsingRec(text1, text2, first+1, second));
        }
        return ans;
    }
    int solveUsingMEMO(string& text1, string& text2, int first, int second, vector<vector<int>>& dp){
        // base case: 
        if(first == text1.length()) return 0;
        if(second == text2.length()) return 0;
        if(dp[first][second] != -1){
            return dp[first][second];
        }
        int ans = 0;
        if(text1[first] == text2[second]){
            ans = 1 + solveUsingMEMO(text1, text2, first+1, second+1, dp);
        }
        else{
            ans = 0 + max(solveUsingMEMO(text1, text2, first, second+1, dp), solveUsingMEMO(text1, text2, first+1, second, dp));
        }
        dp[first][second] = ans;
        return dp[first][second];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        int first = 0;
        int second = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // int ans = solveUsingRec(text1, text2, first, second);
        int ans = solveUsingMEMO(text1, text2, first, second, dp);
        return ans;
    }
};