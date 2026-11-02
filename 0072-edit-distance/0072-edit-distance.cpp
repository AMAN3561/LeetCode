class Solution {
public:
    int solveUsingRec(string& a, string&b, int i, int j){
        //base case
        if(i>= a.length()){
            //word1 vali string end hogye,
            //yani word1 ke length may be word2 se choti hai.
            return b.length()-j;
        }
        if(j>= b.length()){
            //word2 end hogya,
            // word1 ke length may be greater than word2 hai.
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j]){
            //match
            ans= 0+ solveUsingRec(a,b,i+1,j+1);
        }
        else{
            //not match 
            //operation perform karo
            //insert :-
            int opt1= 1+ solveUsingRec(a,b,i,j+1);
            
            // remove :-
            int opt2 = 1+solveUsingRec(a,b,i+1,j);

            // replace :-
            int opt3= 1+ solveUsingRec(a,b,i+1,j+1);

            ans= min(opt1,min(opt2,opt3));
        }
        return ans;
    }
    int solveUsingMEMO(string& a, string&b, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i>= a.length()){
            //word1 vali string end hogye,
            //yani word1 ke length may be word2 se choti hai.
            return b.length()-j;
        }
        if(j>= b.length()){
            //word2 end hogya,
            // word1 ke length may be greater than word2 hai.
            return a.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            //match
            ans= 0+ solveUsingMEMO(a,b,i+1,j+1, dp);
        }
        else{
            //not match 
            //operation perform karo
            //insert :-
            int opt1= 1+ solveUsingMEMO(a,b,i,j+1, dp);
            
            // remove :-
            int opt2 = 1+solveUsingMEMO(a,b,i+1,j, dp);

            // replace :-
            int opt3= 1+ solveUsingMEMO(a,b,i+1,j+1, dp);

            ans= min(opt1,min(opt2,opt3));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length(), -1));
        // int ans= solveUsingRec(word1,word2,i,j);
        int ans= solveUsingMEMO(word1,word2,i,j, dp);
        return ans;
    }
};