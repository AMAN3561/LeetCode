class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9){
            return "";
        }
        string ans(num, '0');
        for(int i = 0; i< num && sum; i++){
            int digit = min(9, sum);
            ans[i] = '0' + digit;
            sum -= digit;
        }
        return ans;
    }
};


// int nines = sum / 9;
//         int remain = sum % 9;

//         string ans(nines, '9');

//         if(remain > 0){
//             ans.push_back(remain + '0');
//         }
//         ans.append(num - ans.length(), '0');

//         return ans;