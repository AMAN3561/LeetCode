class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long maxdiff = 0;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long diffe = abs(nums1[i] - nums2[i]);
            maxdiff = max(maxdiff, diffe);
        }
        vector<long long> diff_freq(maxdiff + 1, 0);
        for(int i = 0; i<n; i++){
            long long diff = abs(nums1[i] - nums2[i]);
            diff_freq[diff]++;
        }
        long long k = k1 + k2;
        for(long long curr_diff = maxdiff; curr_diff > 0 && k > 0; curr_diff--){
            long long  count_operations = min(diff_freq[curr_diff], k);

            diff_freq[curr_diff] -= count_operations;
            diff_freq[curr_diff - 1] += count_operations;
            k -= count_operations;
        }
        for(long long i = 1; i<= maxdiff; i++){
            ans += (diff_freq[i] * i*i);
        }
        return ans;
    }
};
// long long ans = 0;
//         priority_queue<long long> pq;
//         for(int i = 0; i<nums1.size(); i++){
//             long long diff = abs(nums1[i] - nums2[i]);
//             pq.push(diff);
//         }
//         int k = k1 + k2;
//         while(k > 0 && pq.top() > 0){
//             long long largest_diff = pq.top();
//             pq.pop();
//             pq.push(largest_diff - 1);
//             k--;
//         }
//         while(!pq.empty()){
//             long long top_ele = pq.top();
//             pq.pop();
//             ans += top_ele * top_ele;
//         }
//         return ans;