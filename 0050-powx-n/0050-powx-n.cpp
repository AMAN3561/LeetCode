class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        if(N == 0){
            return 1;
        }
        double C_ans = myPow(x, N/2);
        if(N%2 == 0){
            return C_ans * C_ans;
        }
        else{
            return x*C_ans * C_ans;
        }
    }
};