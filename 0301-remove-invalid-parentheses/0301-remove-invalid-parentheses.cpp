class Solution {
public:
    void solve(string& s, int idx, string& curr, int count, unordered_set<string>& st, int& maxleng){
        int n = s.length();
        if(count < 0){
            return;
        }
        if(idx == n){
            if(count == 0){
                if(curr.length() > maxleng){
                    maxleng = curr.length();
                    st.clear();
                }
                if(curr.length() == maxleng){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[idx] != '(' && s[idx] != ')'){
            curr.push_back(s[idx]);
            solve(s, idx + 1, curr, count, st, maxleng);
            curr.pop_back(); // backtrack
            return;
        }

        curr.push_back(s[idx]);
        solve(s, idx + 1, curr, count + (s[idx] == '(' ? 1 : -1), st, maxleng);
        curr.pop_back(); // backtrack
        solve(s, idx + 1, curr, count, st, maxleng);
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        st.clear();
        int maxleng = 0;
        int idx = 0;
        int count = 0;
        string curr = "";
        solve(s, idx, curr, count, st, maxleng);

        return vector<string>(st.begin(), st.end());
    }
};