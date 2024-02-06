class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Get the dimensions of the input matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Initialize pointers for matrix traversal. 
        // Choosing bottom bottom left as initial point for matrix traversal. You can initialize using top right elements as well.
        int r = m-1, c = 0;

        bool found = false;

        while (r >= 0 && c < n) {
            if (matrix[r][c] == target) {
                found = true;  
                break; 
            }
            else if (matrix[r][c] > target) {
                r--;  // Move up in the current column if the current element is greater than the target
            }
            else {
                c++;  // Move right to the next column if the current element is less than the target
            }
        }

        return found;
        
    }
};