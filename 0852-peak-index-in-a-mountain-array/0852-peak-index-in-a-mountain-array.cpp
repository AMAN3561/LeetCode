class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int strt = 0;
        int end = arr.size() - 1;
        while(strt <= end){
            int mid = strt + (end-strt)/2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid;
            }
            else if(arr[mid] > arr[mid - 1]){
                strt = mid;
            }
            else{
                end = mid;
            }
        }
        return end;
    }
};
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int ans = 0;
//         auto max_ele = *max_element(arr.begin(), arr.end());
//         for (int i = 0; i < arr.size(); i++) {
//             if(arr[i] == max_ele){
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };