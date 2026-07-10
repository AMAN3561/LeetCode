class Solution {
public:
    int checkpalindrome(string s, int left, int right){
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;   // Length of the palindrome
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0;
        int maxLength = 1;
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int len1 = checkpalindrome(s, i, i);
            // Even length palindrome
            int len2 = checkpalindrome(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLength);  
    }
};


// int checkpaindrome(string s, int right, int left){
//     while(left >= 0 && right < s.length() && s[left]== s[right]){
//         left--;
//         right++;
//     }
//     return right - left + 1;
// }
// string longestpalindrome(string s){
//     if(s.empty()) return "";
//     int start = 0;
//     int maxlength = 1;
//     for(int i = 0; i<s.length(); i++){
//         int len1 = checkpalindrome(s, i, i);
//         int len2 = checkpalindrome(s, i, i+1);
//         int len = max(len1, len2);
//         if(len > maxlength){
//             maxlength = len;
//             start = i - (len - 1)/2;
//         }
//     }
//     return s.substr(start, maxlength);
// }