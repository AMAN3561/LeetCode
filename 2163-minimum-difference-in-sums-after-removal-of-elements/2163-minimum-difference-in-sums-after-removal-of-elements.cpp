class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<ll> preffix(nums.size(), -1);
        vector<ll> suffix(nums.size(), -1);

        // peffix[i] = sum of first n element from the left to right .
        // suffix[i] = sum of first n element from the right to left .

        ll sum = 0; // minimum n elements sum
        priority_queue<ll>
            pq; // max heap so that max elements can come on top then we can
                // remove them, then the sum becomes minimum, for n elements.
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pq.push(nums[i]);

            // pop out the max elements
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == n) {
                preffix[i] = sum;
            }
        }
        sum = 0; // max n elements sum.
        priority_queue<ll, vector<ll>, greater<ll>>
            pq2; // min heap becoz , while poping the elements the min elements
                 // pops out then the sum will be max for n elements
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            pq2.push(nums[i]);

            // pop out the max elements
            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }

            if (pq2.size() == n) {
                suffix[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, preffix[i] - suffix[i + 1]);
        }
        return ans;
    }
};