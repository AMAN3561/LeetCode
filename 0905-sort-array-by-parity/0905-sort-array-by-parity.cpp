class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        // sort(nums.begin(), nums.end());
        while(i < j){
            if(nums[i] % 2 == 0){
                i++;
            }
            else if(nums[j] % 2 == 1){
                j--;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }
};
