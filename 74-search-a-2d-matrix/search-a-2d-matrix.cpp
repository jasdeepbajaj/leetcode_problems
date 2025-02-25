class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int curr_row = m - 1;
        int curr_col = 0;

        while(curr_row >= 0 && curr_col < n){
            if (matrix[curr_row][curr_col] == target) return true;
            else if (matrix[curr_row][curr_col] > target) curr_row--;
            else curr_col++;
        }

        return false;
    }
};