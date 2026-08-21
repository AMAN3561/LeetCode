class Solution {
public:
    int solveUsingMemorization(int n, vector<int>& dp){
        if(n == 0 || n == 1) return n;

        if(dp[n] != -1){
            // STEP-3 :->
            // ANS ALREADY EXISTS IN DP ARRAY SO RETURN THE EXISITING ANSWWER :
            return dp[n];
        }

        int ans = solveUsingMemorization(n-1, dp) + solveUsingMemorization(n-2, dp);
        // STEP-2 :-> STORE THE ANSWER IN DP ARRAY SO THAT WE DONT HAVE TO COMPUTE THE SAME CALCULATION AGAIN,
        // AVOIDING OVERLAPPING SUBPROBLEM.
        dp[n] = ans;
        return dp[n];
    }
    int fib(int n) {
        // STEP 1:-> FIGURE OUT THE TYPE OF DP.
        // CREATE & INITIALISE, PASS THE DP ARRAY
        vector<int> dp(n+1, -1);
        int ans = solveUsingMemorization(n, dp);
        return ans;
    }
};

// class Solution {
// public:
//     int solveUsingRec(int n){
//         if(n == 0) return 0;
//         if(n == 1) return 1;

//         int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
//         return ans;
//     }
//     int fib(int n) {
//         int ans = solveUsingRec(n);
//         return ans;
//     }
// };