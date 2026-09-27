class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open_bracket;
        vector<int> door(n);
        string ans = "";
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                open_bracket.push(i);
            }
            else if(s[i] == ')'){
                int j = open_bracket.top();
                open_bracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        int flag = 1;
        for(int i = 0; i<n; i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag = -flag;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int> st;
//         string ans = "";
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '(') {
//                 st.push(ans.length());
//             }
//             else if (s[i] == ')') {
//                 int length = st.top();
//                 st.pop();
//                 reverse(ans.begin() + length, ans.end());
//             }
//             else {
//                 ans += s[i];
//             }
//         }
//         return ans;
//     }
// };