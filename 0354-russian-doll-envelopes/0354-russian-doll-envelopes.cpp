class Solution {
public:
    int solveUsingBS(vector<vector<int>>& envelopes){
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i = 1; i<envelopes.size(); i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int idx = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();

                ans[idx] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
        if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = solveUsingBS(envelopes);
        return ans;
    }
};