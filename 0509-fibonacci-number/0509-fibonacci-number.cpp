class Solution {
public:
    int fib(int n) {
        // base cases :-> 
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        // recursive calls :
        int ans = fib(n-1) + fib(n-2);

        return ans;
    }
};