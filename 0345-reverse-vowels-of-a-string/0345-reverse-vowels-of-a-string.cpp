class Solution {
public:
    bool isVowel(char ch){
        // Make the list of vowels
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string reverseVowels(string s) {
        int l = 0;
        int h = s.length()-1;
        while(l<h){
            if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};