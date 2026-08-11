class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0;
        int maxfreq = 0;
        int maxWindow = 0;
        for(int right = 0; right<s.length(); right++){
            // update frequency of current character:
            freq[s[right] - 'A']++;
            // update maximum frequency:
            maxfreq = max(maxfreq, freq[s[right] - 'A']);
            int WindowLength = right - left + 1;
            // if replacements needed > k, shrink window:
            if(WindowLength - maxfreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            // calculate current window length
            WindowLength = right - left + 1;
            maxWindow = max(maxWindow, WindowLength);
        }
        return maxWindow;
    }
};







// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int freq[26] = {0};
//         int left = 0;
//         int right = 0;
//         int maxfreq = 0;
//         int maxWindow = 0;
//         while(right < s.length()) {
//             // update frequency of current character
//             freq[s[right] - 'A']++;
//             // update maximum frequency
//             maxfreq = max(maxfreq, freq[s[right] - 'A']);
//             int WindowLength = right - left + 1;
//             // if replacements needed > k, shrink window
//             if(WindowLength - maxfreq > k) {
//                 freq[s[left] - 'A']--;
//                 left++;
//             }
//             // calculate current window length
//             WindowLength = right - left + 1;
//             maxWindow = max(maxWindow, WindowLength);
//             right++;
//         }
//         return maxWindow;
//     }
// };