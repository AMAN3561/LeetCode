class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ///./././././.-> max-heap & greedy approach :
        // int n = nums.size();
        // priority_queue<long long> pq;
        // for(auto x: nums){
        //     pq.push(1LL * x * x);
        // }
        // for(int i = 0; i<n; i += 2){
        //     nums[i] = pq.top();
        //     pq.pop();
        // }
        // for(int i = 1; i<n; i += 2){
        //     nums[i] = pq.top();
        //     pq.pop();
        // }
        // long long ans = 0;
        // for(int i = 0; i<n; i++){
        //     if(i % 2 == 0){
        //         ans += nums[i];
        //     }
        //     else{
        //         ans -= nums[i];
        //     }
        // }
        // return ans;

        // int n = nums.size();
        // for(auto& x: nums){
        //     x = x * x;
        // }
        // sort(nums.begin(), nums.end());
        // long long sum1 = accumulate(nums.begin(), nums.begin() + n/2, 0LL);
        // long long sum2 = accumulate(nums.begin() + n/2, nums.end(), 0LL);
        // return sum2 - sum1;

        int n = nums.size();
        for(auto& x: nums){
            x = x * x;
        }
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        long long sum1 = accumulate(nums.begin(), nums.begin() + n/2, 0LL);
        long long sum2 = accumulate(nums.begin() + n/2, nums.end(), 0LL);
        return sum2 - sum1;
    }
};