class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> st1(nums2.begin(), nums2.end());

        for(auto it: st){
            if(st1.count(it) == 0){
                ans[0].push_back(it);
            }
        }

        for(auto it: st1){
            if(st.count(it) == 0){
                ans[1].push_back(it);
            }
        }
        return ans;
    }
};