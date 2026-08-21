class Solution {
public:
    void solve(string& num1, string& num2, string& ans, int carry, int i, int j){
        // base case :
        if(i < 0 && j < 0){
            if(carry){
                ans.push_back(carry + '0');
            }
            return;
        }
        // 1 case mai solve karunga :
        int digit1 = (i>= 0) ? num1[i] - '0' : 0;
        int digit2 = (j>= 0) ? num2[j] - '0' : 0;
        int sum  = digit1 + digit2 + carry;
        int digit = sum%10;
        carry = sum / 10;
        ans.push_back(digit + '0');
        solve(num1, num2, ans, carry, i - 1, j - 1);
    }
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans = "";
        int i = num1.length()-1;
        int j = num2.length()-1;
        solve(num1, num2, ans, carry, i, j);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};