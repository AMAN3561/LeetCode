class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int currOR = 0;
        int ans = INT_MAX;
        // nums[i] <= 1e9, so 31 bits are enough
        vector<int> bitCount(32, 0);
        for (int j = 0; j < n; j++) {
            // Add nums[j] to the window
            for (int bit = 0; bit < 32; bit++) {
                if (nums[j] & (1 << bit)) {
                    bitCount[bit]++;
                    currOR |= (1 << bit);
                }
            }
            // Try shrinking the window
            while (i <= j && currOR >= k) {
                ans = min(ans, j - i + 1);
                // Remove nums[i]
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[i] & (1 << bit)) {
                        bitCount[bit]--;
                        if (bitCount[bit] == 0) {
                            currOR &= ~(1 << bit);
                        }
                    }
                }
                i++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};