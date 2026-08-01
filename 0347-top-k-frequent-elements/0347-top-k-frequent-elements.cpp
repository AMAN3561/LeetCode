// class Solution {
// public: // using minheap:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         typedef pair<int, int> P;
//         unordered_map<int, int> mp;
//         for(int num : nums){
//             mp[num]++;
//         }
//         // define minheap
//         priority_queue<P, vector<P>, greater<P>> pq; // minheap

//         // push elements iin minheap. 
//         // maintain size of k only 
//         for(auto &it :mp){
//             int value = it.first;
//             int freq = it.second;

//             pq.push({freq, value});

//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }
//         vector<int> ans ;
//         while(!pq.empty()){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
//     }
// };

// class compare{
//     public:
//         bool operator()(pair<int, int> a, pair<int, int> b){
//             return a.second > b.second;
//         }
// };

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


class Solution {
public: // using minheap:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<vector<int>> bucket(n+1);
        // index ko frequency maan rhe hai 
        // or value ko elements 
        // bucket[i] = elemetns having i frequency.
        for(auto &it : mp){
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }
        // result 
        // pick elements from right to left from the bucket
        // to find max frq element
        vector<int> result;
        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0){
                continue;
            }
            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};