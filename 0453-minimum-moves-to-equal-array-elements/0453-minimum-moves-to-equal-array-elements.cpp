class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minValue = *min_element(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 0; i<n; i++){
            moves += nums[i] - minValue;
        }
        return moves;
    }
};
    /// TLE :
// int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>> pq;
//         int max_val = *max_element(nums.begin(), nums.end());

//         for(int i = 0; i<n; i++){
//             pq.push(nums[i]);
//         }
//         int moves = 0;
//         while(pq.top() != max_val){
//             vector<int> temp;
            
//             for(int i = 0; i<n-1; i++){
//                 int front_ele = pq.top();
//                 pq.pop();

//                 front_ele += 1;
//                 max_val = max(max_val, front_ele);
//                 temp.push_back(front_ele);
//             }
//             for(int num: temp){
//                 pq.push(num);
//             }
//             moves++;
//         }
//         return moves;