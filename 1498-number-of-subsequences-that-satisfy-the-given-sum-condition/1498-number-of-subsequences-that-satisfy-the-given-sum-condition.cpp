class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int left_pointer = 0;
        int right_pointer = nums.size() - 1;
        long long non_empty_subsequent = 0;
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<long long> power(nums.size());
        power[0] = 1;
        for(int i = 1; i<nums.size(); i++){
            power[i] = (power[i - 1] * 2) % MOD;
        }
        while(left_pointer <= right_pointer){
            if(nums[left_pointer] + nums[right_pointer] > target){
                right_pointer--;
            }
            else{
                non_empty_subsequent = (non_empty_subsequent + power[right_pointer - left_pointer]) % MOD;
                left_pointer++;
            }
        }
        return non_empty_subsequent;
    }
};