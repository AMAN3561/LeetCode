class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // storing remainder & index.
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            int remainder = sum % k;
            // check if it is present in the map 
            if(mp.find(remainder) != mp.end()){
                if(i - mp[remainder] >= 2){
                    return true;
                }
            }
            else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         for(int i = 0; i<nums.size(); i++){
//             int sum = 0;
//             for(int j = i; j<nums.size(); j++){
//                 sum += nums[j];
//                 if((j - i + 1 >= 2) &&sum % k == 0){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };