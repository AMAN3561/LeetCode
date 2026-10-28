class Solution {
public:
    // int solveUsingMEMO(vector<int>& nums, int curr, int& prev, vector<vector<int>>& dp){
    //     // base case: 
    //     if(curr >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[curr][prev+1] != -1){
    //         return dp[curr][prev+1];
    //     }
    //     int includeAns = 0;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         includeAns = 1 + solveUsingMEMO(nums, curr+1, curr, dp);
    //     }
    //     int excludeAns = 0 + solveUsingMEMO(nums, curr+1, prev, dp);
    //     int finalAns = max(includeAns, excludeAns);
    //     dp[curr][prev+1] = finalAns;
    //     return finalAns; 
    // }
    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int includeAns = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    includeAns = 1 + dp[curr+1][curr+1];
                }
                int excludeAns = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(includeAns, excludeAns);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMEMO(nums, curr, prev, dp);
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};