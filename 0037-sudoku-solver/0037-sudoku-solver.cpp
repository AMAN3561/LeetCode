class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char digit){
        for(int i = 0; i<9; i++){
            if(board[i][col] == digit){
                return false;
            }
            if(board[row][i] == digit){
                return false;
            }
            int starting_row = row/3 * 3;
            int starting_col = col/3 * 3;
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if(board[starting_row + i][starting_col + j] == digit){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row = 0; row<9; row++){
            for(int col = 0; col<9; col++){
                if(board[row][col] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(isValid(board, row, col, digit)){
                            board[row][col] = digit;

                            if(solve(board) == true){
                                return true;
                            }
                            board[row][col] = '.'; // backtracking.
                        }
                    }  
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};