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
    bool solveUsingTABULATION(vector<int>& nums, int target, int index){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int Idx = n-1; Idx>=0; Idx--){
            for(int Tar = 1; Tar<= target; Tar++){
                bool inc = false;
                if(Tar - nums[Idx] >= 0){
                    inc = dp[Idx+1][Tar - nums[Idx]];
                }
                // Exclude case
                bool exc= dp[Idx+1][Tar];
                dp[Idx][Tar] = (inc || exc); 
            }
        }
        return dp[index][target];
    }
    bool solveUsingTABULATIONSO(vector<int>& nums, int target, int index){
        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        curr[0] = 1;
        next[0] = 1;
        for(int Idx = n-1; Idx>=0; Idx--){
            for(int Tar = 1; Tar<= target; Tar++){
                bool inc = false;
                if(Tar - nums[Idx] >= 0){
                    inc = next[Tar - nums[Idx]];
                }
                // Exclude case
                bool exc= next[Tar];
                curr[Tar] = (inc || exc); 
            }
            // shifting :
            next = curr;
        }
        return next[target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if(sum % 2 !=0) return false; // odd sum
        int target = sum >> 1; 
        // vector<vector<int>> dp(n, vector<int>(target +1, -1));
        // return solveUsingMEMO(nums,target,0, dp);
        int index = 0;
        // return solveUsingTABULATION(nums, target, index);
        return solveUsingTABULATIONSO(nums, target, index);
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