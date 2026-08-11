class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minimumlength = INT_MAX;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                minimumlength = min(minimumlength, right - left + 1);

                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(minimumlength == INT_MAX){
            return 0;
        }
        return minimumlength;
    }
};