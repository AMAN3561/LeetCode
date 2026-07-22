class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        // Count zeros
        for (int x : arr) {
            if (x == 0)
                zeros++;
        }
        int i = n - 1;
        int j = n + zeros - 1;
        while (i >= 0) {
            if (j < n)
                arr[j] = arr[i];

            if (arr[i] == 0) {
                j--;
                if (j < n)
                    arr[j] = 0;
            }
            i--;
            j--;
        }
    }
};


// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> dest(n);
//         int s = 0;
//         int d = 0;
//         while (s < n) {
//             if (arr[s] == 0) {
//                 if (d < n)
//                     dest[d] = 0;
//                 d++;
//                 if (d < n)
//                     dest[d] = 0;
//             } 
//             else {
//                 if (d < n)
//                     dest[d] = arr[s];
//             }
//             s++;
//             d++;
//         }
//         arr = dest;
//     }
// };