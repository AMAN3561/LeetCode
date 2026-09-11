// better approach :
class Solution {
public:
    vector<string> ans;
    void solve(string& curr, int n, int open_Bracket, int close_Bracket){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open_Bracket < n){
            curr.push_back('(');
            solve(curr, n, open_Bracket + 1, close_Bracket);
            curr.pop_back();
        }
        if(close_Bracket < open_Bracket){
            curr.push_back(')');
            solve(curr, n, open_Bracket, close_Bracket + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open_Bracket = 0;
        int close_Bracket = 0;
        solve(curr, n, open_Bracket, close_Bracket);
        return ans;
    }
};
// less better approach :

// class Solution {
// public:
//     vector<string> ans;
//     bool isValid(string& curr){
//         int count = 0;
//         for(char ch: curr){
//             if(ch == '('){
//                 count++;
//             }
//             else{
//                 count--;
//                 if(count < 0){
//                     return false;
//                 }
//             }
//         }
//         return count == 0;
//     }
//     void solve(string& curr, int n){
//         if(curr.length() == 2*n){
//             if(isValid(curr)){
//                 ans.push_back(curr);
//             }
//             return;
//         }
//         curr.push_back('(');
//         solve(curr, n);
//         curr.pop_back();

//         curr.push_back(')');
//         solve(curr, n);
//         curr.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
//         string curr = "";
//         solve(curr, n);
//         return ans;
//     }
// };