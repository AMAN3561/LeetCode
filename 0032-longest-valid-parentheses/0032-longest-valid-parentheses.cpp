class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0; int right = 0; int maxleng = 0;
        for(char ch : s){
            if(ch == '('){
                left++;
            } 
            else{
                right++;
            }
            if(left == right){
                maxleng = max(maxleng, 2 * right);
            }
            else if(right > left){
                left = right = 0;
            }
        }

        left = right = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '('){
                left++;
            } 
            else{
                right++;
            }
            if(left == right){
                maxleng = max(maxleng, 2 * left);
            }
            else if(left > right){
                left = right = 0;
            }

        }
        return maxleng;
        // stack<int> st; // TC- O(n), SC- O(n)
        // st.push(-1);
        // int maxi = 0;
        // for(int i = 0; i<s.length(); i++){
        //     if(s[i] == '('){
        //         st.push(i);
        //     }
        //     else{
        //         st.pop();
        //         if(st.empty()){
        //             st.push(i);
        //         }
        //         else{
        //             maxi = max(maxi, i - st.top());
        //         }
        //     }
        // }
        // return maxi;
    }
};