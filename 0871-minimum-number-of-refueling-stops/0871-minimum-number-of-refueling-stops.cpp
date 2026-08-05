class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int max_you_can_reach = startFuel;
        int count = 0;
        int idx = 0;
        while(max_you_can_reach < target){
            while(idx < stations.size() && stations[idx][0] <= max_you_can_reach){
                pq.push(stations[idx][1]);
                idx++;
            }
            if(pq.empty()){
                return -1;
            }
            else{
                max_you_can_reach += pq.top();
                pq.pop();
                count++;
            }
        }
        return count;
    }
};