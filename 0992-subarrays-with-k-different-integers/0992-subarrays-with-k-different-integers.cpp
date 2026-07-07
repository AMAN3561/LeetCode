class Solution {
public:
    int different(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        unordered_map<int, int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return different(nums, k) - different(nums, k-1);
    }
};  