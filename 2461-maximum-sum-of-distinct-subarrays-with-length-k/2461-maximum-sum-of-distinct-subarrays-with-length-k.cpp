class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_set<int> st;
        long long current_window_sum = 0;
        long long result = 0;
        while(j < n){
            while(st.count(nums[j])){
                current_window_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            current_window_sum += nums[j];
            st.insert(nums[j]);

            if(j - i + 1 == k){
                result = max(result, current_window_sum);
                current_window_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};