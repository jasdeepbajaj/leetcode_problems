class Solution {
public:
    bool isValidCell(vector<vector<char>>& board, int row, int col){
        char value = board[row][col];
        for (int r = 0; r < 9; r++){
            if (r != row && board[r][col] == value) return false;
        }

        for (int c = 0; c < 9; c++){
            if (c != col && board[row][c] == value) return false;
        }

        int subBoxRowStart = row/3 * 3;
        int subBoxColStart = col/3 * 3;

        for(int i = subBoxRowStart; i< subBoxRowStart + 3; i++){
            for(int j = subBoxColStart; j< subBoxColStart + 3; j++){
                if(i!=row && j!= col && board[i][j] == value) return false;
            }
        }


        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9 ; j++){
                if (board[i][j] != '.' && !isValidCell(board, i, j)) return false;
            }
        }
        return true;
    }

};