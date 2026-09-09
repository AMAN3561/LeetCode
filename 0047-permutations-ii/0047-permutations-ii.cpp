class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i){
        // base case :
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int j = i; j<nums.size(); j++){
            if(used.count(nums[j])){
                continue;
            }
            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        solve(nums, ans, i);
        return ans;
    }
};