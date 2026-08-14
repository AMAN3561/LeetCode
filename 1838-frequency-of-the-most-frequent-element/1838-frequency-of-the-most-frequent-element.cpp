class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0;
        long long right = 0;
        long long sum = 0;
        long long ans = 1;
        while(right < nums.size()) {
            sum += nums[right];
            while (nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};