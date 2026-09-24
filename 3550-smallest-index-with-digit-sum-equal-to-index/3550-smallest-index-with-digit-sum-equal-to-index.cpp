class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 9){
                cout<<nums[i]<<endl;
                int sum = 0;
                int temp = nums[i];
                vector<int> digits(5);
                while(temp > 0){
                    digits.push_back(temp%10);
                    temp = temp/10;
                }   
                sum = accumulate(digits.begin(), digits.end(), 0);
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