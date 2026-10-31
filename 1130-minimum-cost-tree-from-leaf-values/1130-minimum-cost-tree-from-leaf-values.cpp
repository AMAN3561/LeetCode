class Solution {
public:
    int solveUsingRec(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right, vector<vector<int>>& dp){
        if(left == right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left; i<right; i++){
            ans = min(ans, mp[{left, i}]* mp[{i+1, right}] + solveUsingRec(arr, mp, left, i, dp) + solveUsingRec(arr, mp, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> mp;
        for(int i = 0; i<n; i++){
            mp[{i, i}] = arr[i];
            for(int j = i+1; j<n; j++){
                mp[{i, j}] = max(arr[j], mp[{i, j-1}]);
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingRec(arr, mp, 0, n-1, dp);
        return ans;
    }
};