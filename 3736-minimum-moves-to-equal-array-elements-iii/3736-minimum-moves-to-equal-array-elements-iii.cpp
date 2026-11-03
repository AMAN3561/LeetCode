class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            // while(nums[i] - maxVal != 0){
            //     moves++;
            //     nums[i] = nums[i] + 1;
            // }
            // if(nums[i] - maxVal != 0){
            //     moves++;
            //     nums[i] += 1;
            //     i--;
            // }
            moves += maxVal - nums[i];
        }
        return moves;
    }
};