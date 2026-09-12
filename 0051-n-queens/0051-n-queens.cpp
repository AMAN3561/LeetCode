class Solution {
public:
    unordered_map<int,bool> left_thorizontal_check;
    unordered_map<int,bool> upper_left_diagonal_check;
    unordered_map<int,bool> lower_left_diagonal_check;
    bool issafe(int row, int col, vector<string>& board){
        // left horizontal: 
        if(left_thorizontal_check[row]== true){
            return false;
        }

        // left_upper diagonal :
        if(upper_left_diagonal_check[row-col]== true){
            return false;
        }

        /// left_lower diagonal :
        if(lower_left_diagonal_check[row+col]== true){
            return false;
        }
        // there is no attack 
        return true;
    }
    // void storesolution(vector<vector<char>>& board, vector<vector<string>>& ans, int n){
    //     vector<string> temp;
    //     for(int row=0; row<n; row++){
    //         string output= "";
    //        for(int col= 0; col<n; col++){
    //         char ch= board[row][col];
    //         output.push_back(ch);
    //        } 
    //        /// ek string ready hogyi hai 
    //        temp.push_back(output);
    //     }
    //     ans.push_back(temp);
    // }
    void solve(vector<string>& board, vector<vector<string>>& ans, int n, int  col){
        // base case: 
        if(col == n){
            ans.push_back(board);
            return;
        }
        // first case hum solve karenge baaki recursion sambhal lega.
        for(int row=0; row<n; row++){
            if(issafe(row, col, board)){
                left_thorizontal_check[row] = true;
                upper_left_diagonal_check[row-col] = true;
                lower_left_diagonal_check[row+col] = true;
                board[row][col] = 'Q';
                // baaki recursion sambhal lega :
                solve(board, ans, n, col+1);
                // backtracking :
                board[row][col] = '.';
                left_thorizontal_check[row] = false;
                upper_left_diagonal_check[row-col] = false;
                lower_left_diagonal_check[row+col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // vector<vector<char>> board (n, vector<char> (n, '.'));
        vector<string> board(n, string(n, '.'));
        int col=0;
        solve(board, ans, n, col);
        return ans;
    }
};