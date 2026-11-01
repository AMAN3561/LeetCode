class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        vector<int> storing;
        for(int i = 1; i<n; i +=2){
            storing.push_back(stoi(to_string(nums[i-1]) + to_string(nums[i])));
        }
        return *min_element(storing.begin(), storing.end());
    }
};