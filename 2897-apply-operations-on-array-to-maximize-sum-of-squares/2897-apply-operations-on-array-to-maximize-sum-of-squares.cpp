class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        for(auto& it: nums){
            for(int b = 0; b<32; b++){
                if(it & (1 << b)){
                    count[b]++;
                }
            }
        }
        long long ans = 0;
        while(k--){
            long long curr = 0;
            for(int b = 0; b<32; b++){
                if(count[b] > 0){
                    count[b]--;
                    curr = (curr | (1 << b));
                }
            }
            ans = (ans + (curr * curr)) % mod;
        }
        return ans;
    }
};