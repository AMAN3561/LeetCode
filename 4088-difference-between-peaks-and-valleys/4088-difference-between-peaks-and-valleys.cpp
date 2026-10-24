class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> valley;
        for (int i = 0; i < n; i++) {
            if (i > 0 && i + 1 < n && nums[i] > nums[i - 1] &&
                nums[i] > nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        for(int i = 0; i<n; i++){
            if(i > 0 && i + 1 < n && nums[i] < nums[i -1] && nums[i] < nums[i + 1]){
                valley.push_back(nums[i]);
            }
        }
        int ans1 = accumulate(ans.begin(), ans.end(), 0);
        int ans2 = accumulate(valley.begin(), valley.end(), 0);
        
        return ans1- ans2;
    }
};