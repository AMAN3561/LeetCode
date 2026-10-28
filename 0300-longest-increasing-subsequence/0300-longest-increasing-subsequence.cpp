class Solution {
public:
    int solveUsingMEMO(vector<int>& nums, int curr, int& prev, vector<vector<int>>& dp){
        // base case: 
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int includeAns = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            includeAns = 1 + solveUsingMEMO(nums, curr+1, curr, dp);
        }
        int excludeAns = 0 + solveUsingMEMO(nums, curr+1, prev, dp);
        int finalAns = max(includeAns, excludeAns);
        dp[curr][prev+1] = finalAns;
        return finalAns; 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMEMO(nums, curr, prev, dp);
        return ans;
    }
};