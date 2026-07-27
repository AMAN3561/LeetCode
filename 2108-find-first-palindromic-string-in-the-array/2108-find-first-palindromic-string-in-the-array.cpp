// class Solution {
// public:
//     string firstPalindrome(vector<string>& words) {
//         for(string &word : words){
//             int n = word.size();
//             if(equal(word.begin(), word.begin()+ n/2, word.rbegin())){
//                 return word;
//             }
//         }
//         return "";
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(string &word){
//         int l = 0;
//         int r = word.length() - 1;
//         while( l < r){
//             if(word[l] != word[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     string firstPalindrome(vector<string>& words) {
//         for(string &word : words){
//             if(isPalindrome(word)){
//                 return word;
//             }
//         }
//         return "";
//     }
// };



class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            int left = 0;
            int right = words[i].size() - 1;
            bool palindrome = true;
            while (left < right) {
                if (words[i][left] != words[i][right]) {
                    palindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (palindrome) {
                return words[i];
            }
        }
        return "";
    }
};


