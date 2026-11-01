class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 1; i<n; i+=2){
            int merged = stoi(to_string(nums[i-1]) + to_string(nums[i]));
            ans = min(ans, merged);
        }
        return ans;
    }
};


//         int n = nums.size();
//         vector<int> storing;
//         for(int i = 1; i<n; i +=2){
//             storing.push_back(stoi(to_string(nums[i-1]) + to_string(nums[i])));
//         }
//         return *min_element(storing.begin(), storing.end());