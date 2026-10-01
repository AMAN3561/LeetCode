class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int front_element = q.front();
            q.pop();
            if(arr[front_element] == 0){
                return true;
            }
            else{
                int positive = front_element + arr[front_element];
                int negative = front_element - arr[front_element];
                if(positive >= 0 && positive < arr.size() && visited[positive] == false){
                    q.push(positive);
                    visited[positive] = true;
                }
                if(negative >= 0 && negative < arr.size() && visited[negative] == false){
                    q.push(negative);
                    visited[negative] = true;
                }
            }
        }
        return false;
    }
};