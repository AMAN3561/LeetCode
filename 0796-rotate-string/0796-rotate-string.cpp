class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        for (int i = 1; i <= n; i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};