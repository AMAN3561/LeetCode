class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lowercase;
        unordered_set<char> uppercase;
        unordered_set<char> digits;
        unordered_set<char> special_char;
        string special = "!@#$";
        for(char ch : password){
            if(ch >= 'a' && ch <= 'z'){
                lowercase.insert(ch);
            }
            else if(ch >= 'A' && ch <= 'Z'){
                uppercase.insert(ch);
            }
            else if(ch >= '0' && ch <= '9'){
                digits.insert(ch);
            }
            else if(special.find(ch) != string::npos){
                special_char.insert(ch);
            }
        }
        int strength = (1*lowercase.size()) + (2*uppercase.size()) + (3*digits.size()) + (5*special_char.size());
        return strength;
    }
};