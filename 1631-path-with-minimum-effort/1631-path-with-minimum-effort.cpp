class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    bool isSafe(int newX, int newY, int row, int col, vector<vector<int>>& diff, int currX, int currY){
        if(newX >= 0 && newY >= 0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]){
            return true;
        }
        else{
            return false;
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
        int destX = row - 1;
        int destY = col - 1;

        // initial state :
        // set src ka distance 0
        diff[0][0] = 0;
        // min heap me entry for src push kardo :
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto topPair = pq.top();
            pq.pop();
            int currDiff = topPair.first;
            auto currentNodeIndexPair = topPair.second;
            int currX = currentNodeIndexPair.first;
            int currY = currentNodeIndexPair.second;

            if(currX == destX && currY == destY){
                return currDiff;
            }
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(isSafe(newX, newY, row, col, diff, currX, currY)){
                    int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);
                    if(newX != destX || newY != destY){
                        pq.push({diff[newX][newY], {newX, newY}});
                    }
                }
            }
        }
        return diff[destX][destY];
    }
};