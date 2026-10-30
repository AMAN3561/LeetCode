class Solution {
public:
    bool solveUsingMEMO(vector<int>& nums, int target, int index, vector<vector<int>>& dp){
        // Base case
        if(index >= nums.size()) return false;
        if(target == 0) return true;
        if(target < 0) return false;
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        // Include case
        bool inc = solveUsingMEMO(nums, target - nums[index], index+1 ,dp);

        // Exclude case
        bool exc= solveUsingMEMO(nums, target, index+1, dp);
        dp[index][target] = (inc || exc); 
        return inc || exc;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if(sum % 2 !=0) return false; // odd sum
        int target = sum >> 1; 
        vector<vector<int>> dp(n, vector<int>(target +1, -1));
        return solveUsingMEMO(nums,target,0, dp);
    }
};


// practice : 

        // bool solve(vector<int>& nums, int target, int index){
        // if(index >= nums.size()) return false;
        // if(target == 0) return true;
        // if(target < 0) return false;

        // // include case :
        // bool inc = solve(nums, target - nums[index], index + 1);

        // // exclude case :
        // bool exc = solve(nums, target, index + 1);

        // return inc || exc;
        // }

        // bool canPartition(vector<int>& nums){
        //     int sum = accumulate(nums.begin(), nums.end(), 0);
        //     if(sum % 2 != 0) return false;
        //     int target= sum >> 1;
        //     return solve(nums, target, 0);
        // }