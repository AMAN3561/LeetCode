class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = getNext(slow);
            fast = getNext(fast);
            fast = getNext(fast);
        } while (slow != fast);
        return slow == 1;
    }
};



// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_set<int> seen;
//         while(n != 1 && !seen.count(n)){
//             seen.insert(n);
//             int sum = 0;
//             while(n > 0){
//                 int digit = n % 10;
//                 sum += digit*digit;
//                 n /= 10;
//             }
//             n = sum;
//         }
//         return n == 1;
//     }
// };