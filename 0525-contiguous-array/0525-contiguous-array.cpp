class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int current_sum = 0;
        int result = 0;
        

        unordered_map<int, int> mp; // storing currentsum & index.
        mp[0] = -1;
        for(int i = 0; i<n; i++){
            current_sum += (nums[i] == 1) ? 1 : -1;

            if(mp.find(current_sum) != mp.end()){
                result = max(result, i - mp[current_sum]);
            }
            else{
                mp[current_sum] = i;
            }
        }
        return result;
    }
};