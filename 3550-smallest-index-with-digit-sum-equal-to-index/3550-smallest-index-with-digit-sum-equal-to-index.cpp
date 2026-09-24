class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 9){
                int sum = 0;
                int temp = nums[i];
                while(temp > 0){
                    sum += temp% 10;
                    temp = temp/10;
                }   
                if(sum == i){
                    return i;
                }
            }
            else{
                if(nums[i] == i){
                    return i;
                }
            }
        }
        return -1;
    }
};