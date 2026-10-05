class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int score = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else{ // s[i] == ')'
                if(s[i - 1] == '('){
                    score = st.top() + 1;
                }
                else{
                    score = st.top() + (2 * score);
                }
                st.pop();
            }
        }
        return score;
    }
};