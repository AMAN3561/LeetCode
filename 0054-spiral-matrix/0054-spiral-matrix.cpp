class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int startingrow = 0;
        int startingcols = 0;
        int endingrow = n-1;
        int endingcols = m-1;


        vector<int> ans;

        while(startingrow<= endingrow && startingcols<= endingcols){
            for(int col= startingcols; col<=endingcols; col++){
                ans.push_back(matrix[startingrow][col]);
            }
            startingrow++;

            for(int row= startingrow; row<= endingrow; row++){
                ans.push_back(matrix[row][endingcols]);
            }
            endingcols--;

            if(startingrow<= endingrow){
                for(int col= endingcols; col>=startingcols; col--){
                ans.push_back(matrix[endingrow][col]);
            }
            endingrow--;
        }
            if(startingcols<= endingcols){
                for(int row= endingrow; row>=startingrow; row--){
            ans.push_back(matrix[row][startingcols]);
            }
            startingcols++;
            }
        }
        return ans;
    }

};