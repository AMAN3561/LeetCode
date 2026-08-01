// class compare{
//     public:
//         bool operator()(pair<int, int> a, pair<int, int> b){
//             return a.second > b.second;
//         }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> P;
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        // define minheap
        priority_queue<P, vector<P>, greater<P>> pq; // minheap


        // push elements iin minheap. 
        // maintain size of k only 
        for(auto &it :mp){
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         vector<int> ans;
//         vector<pair<int, int>> vec;
//         for(int num : nums){
//             mp[num]++;
//         }
//         for(auto it : mp){
//             vec.push_back({it.first, it.second});
//         }
//         sort(vec.begin(), vec.end(), compare());

//         for(int i = 0; i<k; i++){
//             ans.push_back(vec[i].first);
//         }
//         return ans;
//     }
// };