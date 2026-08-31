class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> highest_altitude(gain.size() + 1, 0);
        highest_altitude[0] = gain[0];
        for(int i = 1; i<gain.size(); i++){
            highest_altitude[i] = highest_altitude[i - 1] + gain[i];

        }
        int ans = *max_element(highest_altitude.begin(), highest_altitude.end());
        return ans;
    }
};