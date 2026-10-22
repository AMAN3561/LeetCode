class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n) return false;

        if((s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};


        // int n = s.size();
        // for (int i = 1; i <= n; i++) {
        //     rotate(s.begin(), s.begin() + 1, s.end());
        //     if(s == goal){
        //         return true;
        //     }
        // }
        // return false;