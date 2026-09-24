class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 0; i< n+1; i++){
            int temp = i;
            int count = 0;
            while(temp > 0){
                int digit = temp%2;
                temp = temp/2;
                if(digit == 1){
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};