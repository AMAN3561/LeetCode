class Solution {
public:
    typedef pair<int, int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<p, vector<p>> maxPq;
        priority_queue<p, vector<p>, greater<p>> minPq;

        int l = 0;
        int r = 0;
        int maxlength = 0;
        while(r < n){
            maxPq.push({nums[r], r});
            minPq.push({nums[r], r});

            while(maxPq.top().first - minPq.top().first > limit){
                l = min(maxPq.top().second, minPq.top().second) + 1;

                while(maxPq.top().second < l){
                    maxPq.pop();
                }

                while(minPq.top().second < l){
                    minPq.pop();
                }
            }
            maxlength = max(maxlength, r - l + 1);
            r++;
        }
        return maxlength;
    }
};