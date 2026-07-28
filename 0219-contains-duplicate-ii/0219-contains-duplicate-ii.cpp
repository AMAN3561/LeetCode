class Solution {
public: // using sliding window :
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n){
            // step 1- abs(i - j) <= k
            if(abs(i-j) > k){
                st.erase(nums[i]);
                i++; // shrink
            }
            //past mai dekha hia nums[j] ?
            if(st.find(nums[j]) != st.end()){
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};



// class Solution {
// public: // using map .
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for(int i = 0; i<nums.size(); i++){
//             if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k)
//                 return true;
//             else
//                 mp[nums[i]] = i;
//         }
//         return false;
//     }
// };