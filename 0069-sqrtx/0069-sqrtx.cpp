class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        int strt = 1;
        int end = x;
        int ans = 0;
        while(strt <= end){
            long long mid = strt + (end-strt) / 2;
            if(mid * mid == x){
                return mid;
            }
            if(mid * mid < x){
                ans = mid;
                strt = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};