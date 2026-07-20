class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int bestsum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i<nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int c1 = abs(sum - target);
                int c2 = abs(bestsum - target);
                if(c1 < c2){
                    bestsum = sum;
                }
                if(sum == target){
                    return sum;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return bestsum;
    }
};