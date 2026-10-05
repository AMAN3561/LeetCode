class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<n; i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(ans.empty() || first > ans.back()[1]){
                ans.push_back({first, second});
            }
            else{
                ans.back()[1] = max(ans.back()[1], second);
            }
        }
        return ans;
    }
};