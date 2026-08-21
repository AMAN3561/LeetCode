class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minimum_Subarray_Length = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int currOR = 0;
            for(int j = i; j<n; j++){
                currOR |= nums[j];
                if(currOR >= k){
                    minimum_Subarray_Length = min(minimum_Subarray_Length, j - i + 1);
                    break;
                }
            }
        }
        return minimum_Subarray_Length == INT_MAX ? -1 : minimum_Subarray_Length;
    }
};