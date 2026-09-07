class Solution {
public:
    int trailingZeroes(int n) {
        int trailing_Zeroes = 0;
        for(int i = 5; i<=n; i = i*5){
            trailing_Zeroes = trailing_Zeroes + n/i;
        }
        return trailing_Zeroes;
    }
};