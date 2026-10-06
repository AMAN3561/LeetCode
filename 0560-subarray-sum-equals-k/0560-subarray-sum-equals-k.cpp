// optimal approach :->
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preffix_sum(n, 0);
        unordered_map<int, int> mp;
        int count = 0;
        preffix_sum[0] = nums[0];
        for(int i = 1; i<n; i++){
            preffix_sum[i] = preffix_sum[i - 1] + nums[i];
        }

        for(int j = 0; j<n; j++){
            if(preffix_sum[j] == k){
                count++;
            }
            int val = preffix_sum[j] - k;
            if(mp.contains(val)){
                count += mp[val];
            }
            mp[preffix_sum[j]]++;
        }
        return count;
    }
};
//.. Brute Force :->
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         for(int i = 0; i<nums.size(); i++){
//             int sum = 0;
//             for(int j = i; j<nums.size(); j++){
//                 sum += nums[j];
//                 if(sum == k){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };