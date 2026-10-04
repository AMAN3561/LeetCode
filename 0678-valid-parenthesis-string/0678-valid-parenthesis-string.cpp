class Solution {
public:
        // by recursion :
    // bool checkValid(string& s, int idx, int count){
    //     if(count < 0){
    //         return false;
    //     }
    //     if(idx == s.length()){
    //         return count == 0;
    //     }
    //     if(s[idx] == '('){
    //         return checkValid(s, idx + 1, count + 1);
    //     }
    //     if(s[idx] == ')'){
    //         return checkValid(s, idx + 1, count - 1);
    //     }
    //     return checkValid(s, idx + 1, count + 1) || checkValid(s, idx + 1, count -1) || checkValid(s, idx + 1, count);
    // }
    bool checkValidString(string s) {
        // int idx = 0;
        // int count = 0;
        // bool ans = checkValid(s, idx, count);
        // return ans;
        //.././././././././././././/././././.
        int min = 0;
        int max = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                min += 1;
                max += 1;
            }
            else if(s[i] == ')'){
                min -= 1;
                max -= 1;
            }
            else{
                min -= 1;
                max += 1;
            }

            if(min < 0){
                min = 0;
            }
            if(max < 0) {
                return false;
            }
        }
        return min == 0;
    }
};