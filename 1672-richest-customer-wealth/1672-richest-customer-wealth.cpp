class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int cols = accounts[0].size();

        
        int ans = 0;
        for(int i = 0; i< row; i++){
            int sum = 0;
            for(int j = 0; j<cols; j++){
                sum += accounts[i][j];
            }
            ans = max(ans, sum);
        }
        return ans ;
    }
};