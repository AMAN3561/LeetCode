class Solution {
public:
    int solveUsingRec(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right){
        if(left == right){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = left; i<right; i++){
            ans = min(ans, mp[{left, i}]* mp[{i+1, right}] + solveUsingRec(arr, mp, left, i) + solveUsingRec(arr, mp, i+1, right));
        }
        return ans;
    }
    int solveUsingMEMO(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right, vector<vector<int>>& dp){
        if(left == right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left; i<right; i++){
            ans = min(ans, mp[{left, i}]* mp[{i+1, right}] + solveUsingMEMO(arr, mp, left, i, dp) + solveUsingMEMO(arr, mp, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int solveUsingTABULATION(vector<int>& arr, map<pair<int, int>, int>& mp){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int LEFT = n-1; LEFT>=0; LEFT--){
            for(int RIGHT = 0; RIGHT<=n-1; RIGHT++){
                if(LEFT >= RIGHT) continue;
                int ans = INT_MAX;
                for(int i = LEFT; i<RIGHT; i++){
                    ans = min(ans, (mp[{LEFT, i}]* mp[{i+1, RIGHT}] + dp[LEFT][i] + dp[i+1] [RIGHT]));
                }
                dp[LEFT][RIGHT] = ans;
            }
        }
        return dp[0][n-1];
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
        // int ans = solveUsingRec(arr, mp, 0, n-1);
        // int ans = solveUsingMEMO(arr, mp, 0, n-1, dp);
        int ans = solveUsingTABULATION(arr, mp);
        return ans;
    }
};