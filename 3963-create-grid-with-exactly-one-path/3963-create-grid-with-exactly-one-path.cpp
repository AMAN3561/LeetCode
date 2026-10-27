class Solution {
public:
    vector<string> createGrid(int m, int n){
        vector<string> ans(m, string(n, '#'));
        for(int i = 0; i<m; i++){
            ans[i][0] = '.';
        }
        ans[m-1] = string(n, '.');
        return ans;
    }
};