class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int r = m-1, c = 0;

        bool found = false;

        // Loop to search for the target value in the matrix
        while (r >= 0 && c < n) {
            if (matrix[r][c] == target) {
                found = true;  // Set found flag to true if target is found
                break; //get out of the while loop once the element has been found
            }
            else if (matrix[r][c] > target) {
                r--;  // Move left in the current row if the current element is greater than the target
            }
            else {
                c++;  // Move down to the next row if the current element is less than the target
            }
        }

        return found;
        
    }
};