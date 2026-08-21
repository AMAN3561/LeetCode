class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minimum_Subarray_Length = INT_MAX;
        int n = nums.size();
        int i = 0;
        while(i < n){
            int currOR = 0;
            int j = i;
            while(j < n){
                currOR |= nums[j];
                if(currOR >= k){
                    minimum_Subarray_Length = min(minimum_Subarray_Length, j - i + 1);
                    break;
                }
                j++;
            }
            i++;
        }
        return minimum_Subarray_Length == INT_MAX ? -1 : minimum_Subarray_Length;
    }
};