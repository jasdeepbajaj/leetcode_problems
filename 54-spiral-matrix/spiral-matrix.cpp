class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v1;
    

        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        while (top <= bottom && left <= right) {
            // for top row
            for (int col = left; col <= right; col++)
                v1.push_back(matrix[top][col]);
            top++;

            // for right column
            for (int row = top; row <= bottom; row++)
                v1.push_back(matrix[row][right]);
            right--;

            // for bottom row
            if (top <= bottom) { // check to avoid duplicate printing in odd-rowed matrices
                for (int col = right; col >= left; col--)
                    v1.push_back(matrix[bottom][col]);
                bottom--;
            }

            // for left column
            if (left <= right) { // check to avoid duplicate printing in odd-columned matrices
                for (int row = bottom; row >= top; row--)
                    v1.push_back(matrix[row][left]);
                left++;
            }
        }

        return v1;
    }
};
