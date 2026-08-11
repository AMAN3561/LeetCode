class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int zero_count = 0;
        int Max_subarray_Window = 0;
        while(r < nums.size()){
            if(nums[r] == 0){
                zero_count++;
            }
            while(zero_count > 1){
                if(nums[l] == 0){
                    zero_count--;
                }
                l++;
            }
            Max_subarray_Window = max(Max_subarray_Window, r - l);
            r++;
        }
        return Max_subarray_Window;
    }
};















// class Solution {
// public: // TLE :
//     int findMax(vector<int>& nums, int skip_index){
//         int n = nums.size();
//         int currentsubarraylength = 0;
//         int maxlength = 0;

//         for(int i = 0; i<n; i++){
//             if(i == skip_index){
//                 continue;
//             }
//             if(nums[i] == 1){
//                 currentsubarraylength++;
//                 maxlength = max(maxlength, currentsubarraylength);
//             }
//             else{
//                 currentsubarraylength = 0;
//             }
//         }
//         return maxlength;
//     }
//     int longestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int result = 0;
//         int countzero = 0;
//         for(int i = 0; i<n; i++){
//             if(nums[i] == 0){
//                 countzero++;
//                 result = max(result, findMax(nums, i));
//             }
//         }
//         if(countzero == 0){
//             return n - 1;
//         }
//         return result;
//     }
// };