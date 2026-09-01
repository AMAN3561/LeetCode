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

// optimal approach :->
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixsum(n, 0);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }
        unordered_map<int, int> m; // prefixsum, frequency
        for (int j = 0; j < n; j++) {
            if (prefixsum[j] == k)
                count++;

            int val = prefixsum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }
            // if (m.find(prefixsum[j]) == m.end()) {
            //     m[prefixsum[j]] = 0;
            // }
            m[prefixsum[j]]++;
        }
        return count;
    }
};


// unordered_map<int, int> mp;
// int count = 0;

// prefixsum[0] = arr[0];
// for(int i = 1; i<arr.size(); i++){
//     prefixsum[i] = prefixsum[i-1] + arr[i];
// }

// for(int j = 0; j<arr.size(); j++){
//     if(prefixsum[j] == k){
//         count++;
//     }
//     int val = prefixsum[j] - k;
//     if(mp.find(val) != mp.end()){
//         count += mp[val];
//     }
//     if(mp.find(prefixsum[j]) == mp.end()){
//         mp[prefixixsum[j]] = 0;
//     }
//     mp[prefixsum[j]]++;
// }
// return count;


