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
    int solveUsingTABULATION(string& text1, string& text2, int first, int second, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int FIRST = n-1; FIRST>=first; FIRST--){
            for(int SECOND = m-1; SECOND>=second; SECOND--){
                int ans = 0;
                if(text1[FIRST] == text2[SECOND]){
                    ans = 1 + dp[FIRST+1][SECOND+1];
                }
                else{
                    ans = 0 + max(dp[FIRST][SECOND+1], dp[FIRST+1][SECOND]);
                }
                dp[FIRST][SECOND] = ans;
            }
        }
        return dp[first][second];
    }
    int solveUsingTABULATIONSO(string& text1, string& text2, int first, int second, int n, int m){
        vector<int> next(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int FIRST = n-1; FIRST>=first; FIRST--){
            for(int SECOND = m-1; SECOND>=second; SECOND--){
                int ans = 0;
                if(text1[FIRST] == text2[SECOND]){
                    ans = 1 + next[SECOND+1];
                }
                else{
                    ans = 0 + max(curr[SECOND+1], next[SECOND]);
                }
                curr[SECOND] = ans;
            }
            // shifting :
            next = curr;
        }
        return next[second];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        int first = 0;
        int second = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // int ans = solveUsingRec(text1, text2, first, second);
        // int ans = solveUsingMEMO(text1, text2, first, second, dp);
        // int ans = solveUsingTABULATION(text1, text2, first, second, n, m);
        int ans = solveUsingTABULATIONSO(text1, text2, first, second, n, m);
        return ans;
    }
};