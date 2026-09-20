class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq; // minheap
        int ans = 0;
        for(auto& it: intervals){
            int start = it[0];
            while(!pq.empty() && pq.top() < start){
                pq.pop();
            }
            ans += pq.size();
            pq.push(it[1]);
        }
        return ans;
    }
};