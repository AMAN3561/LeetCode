class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        vector<int> ps(n);
        ps[0] = nums[0];
        for(int i = 1; i<n; i++){
            ps[i] = ps[i - 1] + nums[i];
        }
        for(int i = 0; i<n; i++){
            int val = ((ps[i] % k) + k) % k;
            if(mp.find(val) != mp.end()){
                ans += mp[val];
            }
            mp[val]++;
        }
        return ans;
    }
};