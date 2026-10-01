class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            // opening brackets :
            if(ch == '(' || ch == '[' || ch == '{'){
                //insert :
                st.push(ch);
            }
            else{
                // Conditions :
                //closing brackets
                // match
                // no match
                // pre- check for empty stack that is the stack empty ?
                if(st.empty()){
                    // no match 
                    return false;
                }
                if(ch == ')' && st.top() != '('){
                    return false;
                }
                else if(ch == ']' && st.top() != '['){
                    return false;
                }
                else if(ch == '}' && st.top() != '{'){
                    return false;
                }
                else{
                    // match found :
                    st.pop();
                }
            }
        }
        // yaha pr galti hoti hai so be extra cautious :
        if(st.empty()){
            // iska matlb saare bracket cancel ho gye hai 
            return true;
        }
        else{
            // iska matlb saare brackets mai se kuch bracket stack mai bach gye hai.
            return false;
        }
    }
};



// stack<char> st;
// for(int i = 0; i<s.length(); i++){
//     char ch = s[i];
//     if(ch =='(' || ch == '[' || ch == '{'){
//         st.push(ch);
//     }
//     else{
//         if(st.empty()){
//             return false;
//         }
//         if(ch == ')' && st.top() != '('){
//             return false;
//         }
//         else if(ch == ']' && st.top() != '['){
//             return false;
//         }
//         else if(ch == '}' && st.top() != '{'){
//             return false;
//         }
//         else{
//             st.pop();
//         }
//     }
// }

// if(st.empty()){
//     return true;
// }
// else{
//     return false;
// }