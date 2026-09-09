class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index, vector<int>& subset){
        // base case :
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        // include case :
        subset.push_back(nums[index]);
        solve(nums, ans, index+1, subset);
        subset.pop_back();

        // exclude case :
        solve(nums, ans, index + 1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int index = 0;
        solve(nums, ans, index, subset);
        return ans;
    }
};