class Solution {
public:
    int solveUsingRec(string& s, int n, int left, int right){
        // base case :
        if(left >= n){
            return 0;
        }
        if(left > right){
            return 0;
        }
        if(left == right){
            return 1;
        }
        int ans = 0;
        if(s[left] == s[right]){
            ans = 2 +  solveUsingRec(s, n, left+1, right-1);
        }
        else{
            ans = 0 + max(solveUsingRec(s, n, left+1, right), solveUsingRec(s, n, left, right-1));
        }
        return ans;
    }
    int solveUsingMEMO(string& s, int n, int left, int right, vector<vector<int>>& dp){
        // base case :
        if(left >= n){
            return 0;
        }
        if(left > right){
            return 0;
        }
        if(left == right){
            return 1;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = 0;
        if(s[left] == s[right]){
            ans = 2 +  solveUsingMEMO(s, n, left+1, right-1, dp);
        }
        else{
            ans = 0 + max(solveUsingMEMO(s, n, left+1, right, dp), solveUsingMEMO(s, n, left, right-1, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int solveUsingTABULATION(string& s, int n, int left, int right){
        // base case :
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int LEFT = right; LEFT>=left; LEFT--){
            dp[LEFT][LEFT] = 1;
            for(int RIGHT = LEFT+1; RIGHT<=right; RIGHT++){
                int ans = 0;
                if(s[LEFT] == s[RIGHT]){
                    ans = 2 +  dp[LEFT+1][RIGHT-1];
                }
                else{
                    ans = 0 + max(dp[LEFT+1][RIGHT], dp[LEFT][RIGHT-1]);
                }
                dp[LEFT][RIGHT] = ans;
            }  
        }
        return dp[left][right];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingRec(s, n, left, right);
        // int ans = solveUsingMEMO(s, n, left, right, dp);
        int ans = solveUsingTABULATION(s, n, left, right);
        return ans;
    }
};