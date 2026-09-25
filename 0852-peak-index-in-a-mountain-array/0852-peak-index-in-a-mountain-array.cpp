class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        auto max_ele = *max_element(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if(arr[i] == max_ele){
                ans = i;
            }
        }
        return ans;
    }
};