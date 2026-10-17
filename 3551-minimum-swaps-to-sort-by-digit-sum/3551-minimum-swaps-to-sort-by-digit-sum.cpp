
class Solution {
public:
    struct comp{
    bool operator()(int num1, int num2){
        int num1digit_sum = getdigit_sum(num1);
        int num2digit_sum = getdigit_sum(num2);

        if(num1digit_sum != num2digit_sum){
            return num1digit_sum < num2digit_sum;
        }
        return num1 < num2;
    }
    };
    static int getdigit_sum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num = num/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);

        sort(sorted.begin(), sorted.end(), comp());

        unordered_map<int, int> idx_loc;
        for(int i = 0; i<n; i++){
            idx_loc[nums[i]] = i;
        }

        int swaps = 0;
        for(int i = 0; i<n; i++){
            int expectedval = sorted[i];
            int currval = nums[i];

            if(expectedval == currval) continue;

            int idx = idx_loc[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;
            
            idx_loc[expectedval] = i;
            idx_loc[currval] = idx;

            swaps++;
        }
        return swaps;
    }
};