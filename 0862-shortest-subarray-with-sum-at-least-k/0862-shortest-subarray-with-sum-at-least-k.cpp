class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        vector<long long> cummulative_sum(n, 0);
        deque<int> dq;
        int leng = INT_MAX;
        while(j < n){
            if(j == 0){
                cummulative_sum[j] = nums[j];
            }else{
                cummulative_sum[j] = cummulative_sum[j - 1] + nums[j];
            }
            if(cummulative_sum[j] >= k){
                leng = min(leng, j + 1);
            }

            while(!dq.empty() && cummulative_sum[j] - cummulative_sum[dq.front()] >= k){
                leng = min(leng, j - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cummulative_sum[j] <= cummulative_sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return leng == INT_MAX ? -1 : leng;
    }
};