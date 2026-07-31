class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(st.top() == ch){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            char element = st.top();
            st.pop();
            ans.push_back(element);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};





// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string ans= "";
//         for(int i=0;i<s.length(); i++){
//             char ch= s[i];
//             if(ans.empty()){
//                 ans.push_back(ch);
//             }
//             else if(ch != ans.back()){
//                 ans.push_back(ch);
//             }
//             else{
//                 ans.pop_back();
//             }
//         }
//         return ans;
//     }
// };