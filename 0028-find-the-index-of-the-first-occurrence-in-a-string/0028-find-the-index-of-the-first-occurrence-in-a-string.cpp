// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.length();
//         int m = needle.length();
//         for(int i = 0; i<= n-m; i++){
//             for(int j = 0; j<m; j++){
//                 if(needle[j] != haystack[i+j]){
//                     break;
//                 }
//                 if(j == m-1){
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length();
        int m = needle.length();
        if (m > n) return -1;
        int i = 0; // haystack pointer
        int j = 0; // needle pointer
        while (i < n) {
            // Characters match
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                // Found complete match
                if (j == m) {
                    return i - m;
                }
            } else {
                // Mismatch: reset needle pointer, adjust haystack pointer
                i = i - j + 1;
                j = 0;
                // Early termination
                if (i > n - m) {
                    return -1;
                }
            }
        }
        return -1;
    }
};