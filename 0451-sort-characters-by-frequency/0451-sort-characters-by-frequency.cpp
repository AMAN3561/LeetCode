class Solution {
public:
    typedef pair<int, char> p;
    string frequencySort(string s) {
        int n = s.length();
        string ans = "";
        unordered_map<char, int> mp;
        for(auto it: s){
            mp[it]++;
        }
        priority_queue<p, vector<p>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            while(front.first > 0){
                ans.push_back(front.second);
                front.first--;
            }
        }
        return ans;
    }
};