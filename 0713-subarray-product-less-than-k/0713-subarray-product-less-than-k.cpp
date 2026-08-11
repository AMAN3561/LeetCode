class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int count_of_product_lessthan_k = 0;
        int product = 1;
        while(r < n){
            product *= nums[r];
 
            while(product >= k && l <= r){
                product /= nums[l];
                l++;
            }
            count_of_product_lessthan_k += r - l + 1;
            r++;
        }
        return count_of_product_lessthan_k;
    }
};


// class Solution {
// public: // O(n^2)
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             int product = 1;
//             for(int j = i; j < n; j++) {
//                 product *= nums[j];
//                 if(product < k) {
//                     count++;
//                 }
//                 else {
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };
