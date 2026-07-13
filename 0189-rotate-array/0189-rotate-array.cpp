class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n;
        vector<int> temp;
        for(int i= n-k; i<=n-1; i++){
            int value= nums[i];
            temp.push_back(value);
        }
        for(int i=n-1; i>=0; i--){
            if(i-k >=0){
                nums[i]= nums[i-k];
            }
        }
        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
    }
};