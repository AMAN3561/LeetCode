class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(ans.length());
            }
            else if (s[i] == ')') {
                int length = st.top();
                st.pop();
                reverse(ans.begin() + length, ans.end());
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
