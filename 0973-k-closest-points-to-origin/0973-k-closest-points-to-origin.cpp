class Solution {
public:
    class comp{
        public:
            bool operator()(pair<int, int>& a, pair<int,int>& b){
                int distA = a.first*a.first + a.second* a.second;
                int distB = b.first*b.first + b.second* b.second;
                return distA > distB;
            }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<vector<int>> ans;

        for(auto point : points){
            pq.push({point[0], point[1]});
        }
        while(!pq.empty() && k){
            auto& topPoints = pq.top();
            ans.push_back({topPoints.first, topPoints.second});
            pq.pop();
            k--;
        }
        return ans;
    }
};