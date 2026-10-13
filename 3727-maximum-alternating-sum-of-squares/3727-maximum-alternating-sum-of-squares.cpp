class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(auto& x: nums){
            x = x * x;
        }
        sort(nums.begin(), nums.end());
        long long sum1 = accumulate(nums.begin(), nums.begin() + n/2, 0LL);
        // cout<< sum1<<" ";
        long long sum2 = accumulate(nums.begin() + n/2, nums.end(), 0LL);
        // cout<<sum2<<" ";
        return sum2 - sum1;
    }
};