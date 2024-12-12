class Solution {

public:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i<n-1; ++i){
            for(int j = i+1; j<n;++j ){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverse_row(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0; i<n; ++i){
            // vector<int> row = matrix[i];
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_row(matrix);

        
    }
};