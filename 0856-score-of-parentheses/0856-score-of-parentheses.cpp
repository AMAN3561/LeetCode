class Solution { // T.C - O(n), S.C - O(1).
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                depth++;
            }
            else{ // s[i] == ')'
                depth--;
                if(s[i - 1] == '('){
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};
// class Solution { T.C - O(n), S.C - O(n).
// public:
//     int scoreOfParentheses(string s) {
//         stack<char> st;
//         int score = 0;
//         for(int i = 0; i<s.length(); i++){
//             if(s[i] == '('){
//                 st.push(score);
//                 score = 0;
//             }
//             else{ // s[i] == ')'
//                 if(s[i - 1] == '('){
//                     score = st.top() + 1;
//                 }
//                 else{
//                     score = st.top() + (2 * score);
//                 }
//                 st.pop();
//             }
//         }
//         return score;
//     }
// };