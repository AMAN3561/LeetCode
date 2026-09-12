class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.length() - 1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void solve(string& s, int index, vector<string>& curr_partition){
        // base case :
        if(index == s.length()){
            ans.push_back(curr_partition);
            return;
        }
        for(int i = index; i<s.length(); i++){
            string part = s.substr(index, i - index + 1);
            if(isPalindrome(part)){
                curr_partition.push_back(part);
                solve(s, i + 1, curr_partition);
                curr_partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr_partition;
        int index = 0;
        solve(s, index, curr_partition);
        return ans;
    }
};