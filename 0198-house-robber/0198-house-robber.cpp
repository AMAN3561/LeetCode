class Solution {
public:
    int solveUsingRec(vector<int>& nums, int index){
        // base case:-
        if(index >=nums.size()){
            return 0;
        }
        // Include-
        int includekaans= nums[index] + solveUsingRec(nums,index+2);
        //Exclude-
        int excludekaans= 0 + solveUsingRec(nums,index+1);
        int finalans = max(includekaans,excludekaans);
        return finalans;
    }
    int solveUsingMEMO(vector<int>& nums, int index, vector<int>& dp){
        // base case:-
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        // Include-
        int includekaans= nums[index] + solveUsingMEMO(nums,index+2, dp);
        //Exclude-
        int excludekaans= 0 + solveUsingMEMO(nums,index+1, dp);
        int finalans = max(includekaans,excludekaans);
        dp[index] = finalans;
        return dp[index];
    }
    int solveUsingTABULATION(vector<int>& nums, int index){
        int n = nums.size();
        vector<int> dp(n+3, 0);
        for(int I = n-1; I>=0; I--){
            // Include-
            int includekaans= nums[I] + dp[I+2];
            //Exclude-
            int excludekaans= 0 + dp[I+1];
            int finalans = max(includekaans,excludekaans);
            dp[I] = finalans;
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int index=0;
        // int ans= solveUsingRec(nums,index, dp);
        // int ans = solveUsingMEMO(nums, index, dp);
        int ans = solveUsingTABULATION(nums, index);
        return ans;
    }
};