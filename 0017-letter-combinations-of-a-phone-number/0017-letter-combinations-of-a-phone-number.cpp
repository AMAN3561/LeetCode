class Solution {
public:
    void solve(string digits, vector<string>& ans, string output, int index, string mapping[]){
        // base case :
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, ans, output, index + 1, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
        if(digits.length() == 0){
            return ans;
        }
        string output = "";
        int index = 0;
        solve(digits, ans, output, index, mapping);
        return ans;
    }
};