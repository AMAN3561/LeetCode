class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> CummXOR(n, 0);

        CummXOR[0] = arr[0];
        for(int i = 1; i<n; i++){
            CummXOR[i] = CummXOR[i - 1] ^ arr[i];
        }
        vector<int> ans;
        for(vector<int>& query : queries){
            int L = query[0];
            int R = query[1];

            int xor_val = CummXOR[R] ^ (L == 0 ? 0 : CummXOR[L - 1]);
            ans.push_back(xor_val);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         vector<int> ans;
//         for(int i = 0; i<queries.size(); i++){
//             int L = queries[i][0];
//             int R = queries[i][1];
//             int x = 0;
//             for(int j = L; j<=R; j++){
//                 x = x ^ arr[j];
//             }
//             ans.push_back(x);
//         }
//         return ans;
//     }
// };