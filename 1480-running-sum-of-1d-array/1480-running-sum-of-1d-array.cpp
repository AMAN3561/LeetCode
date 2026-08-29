class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix_sum;
        int prefix = nums[0];
        prefix_sum.push_back(prefix);

        for(int i = 1; i<nums.size(); i++){
            prefix += nums[i];
            prefix_sum.push_back(prefix);
        }
        return prefix_sum;
    }
};