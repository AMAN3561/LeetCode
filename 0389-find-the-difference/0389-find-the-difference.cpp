class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(int i = 0; i<s.length(); i++){
            mp1[s[i]]++;
        }
        for(int j = 0; j<t.length(); j++){
            mp2[t[j]]++;
        }
        for(auto it : mp2){
            if(mp1[it.first] != it.second){
                return it.first;
            }
        }
        return '\0';  // added
    }
};