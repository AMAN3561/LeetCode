class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev){
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solveUsingTabulation(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int includeAns = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev])){
                    int heightToAdd = cuboids[curr][2];
                    includeAns = heightToAdd + nextRow[curr+1];
                }
                int excludeAns = 0 + nextRow[prev+1];
                currRow[prev+1] = max(includeAns, excludeAns);
            }
            // shifting : 
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
       for(auto& cuboid: cuboids){
        sort(cuboid.begin(), cuboid.end());
       } 
       sort(cuboids.begin(), cuboids.end());

        int ans = solveUsingTabulation(cuboids);
        return ans;
    }
};