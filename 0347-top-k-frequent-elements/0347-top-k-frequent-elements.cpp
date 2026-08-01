class compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<pair<int, int>> vec;
        for(int num : nums){
            mp[num]++;
        }
        for(auto it : mp){
            vec.push_back({it.first, it.second});
        }
        sort(vec.begin(), vec.end(), compare());

        for(int i = 0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};