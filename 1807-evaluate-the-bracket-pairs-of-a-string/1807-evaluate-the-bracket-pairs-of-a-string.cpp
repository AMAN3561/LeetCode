class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> key_val;
        for (int i = 0; i < knowledge.size(); i++) {
            key_val[knowledge[i][0]] = knowledge[i][1];
        }
        int i = 0;
        string result = "";
        while(i < s.length()){
            if(isalpha(s[i])){
                result.push_back(s[i]);
            }
            else{
                // '('
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                result += key_val.count(temp) ? key_val[temp] : "?";
            }
            i++;
        }
        return result;
    }
};