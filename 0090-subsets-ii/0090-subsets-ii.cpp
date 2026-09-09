class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index, vector<int>& subset){
        // base case :
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        solve(nums, ans, index + 1, subset);
        subset.pop_back();
        index++;
        // skipping if the duplicate element present in the vector :
        while(index < nums.size() && nums[index] == nums[index - 1]){
            index++;
        }
        solve(nums, ans, index, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        int index = 0;
        solve(nums, ans, index, subset);
        return ans;
    }
};