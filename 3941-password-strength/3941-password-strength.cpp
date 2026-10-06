class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lowercase;
        unordered_set<char> uppercase;
        unordered_set<char> digits;
        unordered_set<char> special_char;
        string special = "!@#$";
        for(char ch : password){
            if(islower(ch)){
                lowercase.insert(ch);
            }
            else if(isupper(ch)){
                uppercase.insert(ch);
            }
            else if(isdigit(ch)){
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