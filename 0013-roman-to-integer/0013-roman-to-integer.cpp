class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanint = {{'I', 1},
                                             {'V', 5},
                                             {'X', 10},
                                             {'L', 50},
                                             {'C', 100},
                                             {'D', 500},
                                             {'M', 1000}};

        int result = 0;
        for(int i = 0; i<s.length(); i++){
            if(i + 1 < s.length() && romanint[s[i]] < romanint[s[i + 1]]){
                result += romanint[s[i + 1]] - romanint[s[i]];
                i++;
            }
            else{
                result += romanint[s[i]];
            }
        }
        return result;
    }
};