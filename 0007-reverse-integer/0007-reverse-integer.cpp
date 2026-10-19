class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool neg = (x < 0);
        if(neg){
            s.erase(0, 1);
        }
        ::reverse(s.begin(), s.end());
        long long ans = stoll(s);
        if(neg) ans = -ans;
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }

        return (int)ans;
    }
};