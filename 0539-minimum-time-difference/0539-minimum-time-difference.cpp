class Solution {
public:
    int ConvertToMinutes(string& time){
        int hours = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3,2));
        return 60 * hours + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> totalminutes;
        for(auto time: timePoints){
            totalminutes.push_back(ConvertToMinutes(time));
        }
        sort(totalminutes.begin(), totalminutes.end());
        int ans = INT_MAX;
        for(int i = 0; i<totalminutes.size() - 1; i++){
            ans = min(ans, totalminutes[i + 1] - totalminutes[i]);
        }
        int lastdifference = totalminutes[0] + 1440 - totalminutes[totalminutes.size()-1];
        ans = min(ans, lastdifference);
        return ans;
    }
};