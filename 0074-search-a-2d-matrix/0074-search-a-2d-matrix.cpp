class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int cols= matrix[0].size();
        int total= row*cols;
        int s=0;
        int e= total-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            int rowIndex= mid/cols;
            int colsIndex= mid % cols;
            if(matrix[rowIndex][colsIndex]==target){
                return true;
            }
            if(matrix[rowIndex][colsIndex]< target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};